# build arm64 kernel and userspace
FROM ubuntu:18.04 as buildroot
WORKDIR /workdir
RUN apt-get update && apt-get install -yy make g++ build-essential git file wget cpio unzip rsync bc libssl-dev curl
ENV FORCE_UNSAFE_CONFIGURE=1
RUN curl https://buildroot.org/downloads/buildroot-2020.05.2.tar.gz | tar -xz --strip-components=1
COPY example_buildroot_config .config
RUN make

# build captive
FROM ubuntu as captive
WORKDIR /workdir
RUN apt-get update && apt-get install -yy make g++ build-essential
COPY . .
RUN make

# export image
FROM ubuntu
WORKDIR /workdir

COPY --from=buildroot /workdir/output/images/Image kernel
COPY --from=buildroot /workdir/output/images/rootfs.ext2 .
COPY --from=captive /workdir/arch/arm64.arch .
COPY --from=captive /workdir/captive-platform.dtb .
COPY --from=captive /workdir/bin/captive .

COPY --from=captive /workdir/entrypoint.sh .

CMD [ "./entrypoint.sh" ]

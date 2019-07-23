ENTRY(start)

PHDRS
{
	text PT_LOAD FILEHDR PHDRS;
	data PT_LOAD;
}

SECTIONS
{
	. = 1M;
	_LMA_START = .;

	. = 0xFFFFFFFF80000000 + _LMA_START;

	_TEXT_START = .;
	.text : AT(_LMA_START)
	{
		*(.text)
		*(.text.*)
	} :text
	_TEXT_END = .;

	. = ALIGN(4096);

	_RODATA_START = .;
	.rodata :
	{
		*(.rodata)
		*(.rodata.*)
	}
	_RODATA_END = .;
	
	. = ALIGN(4096);

	_DATA_START = .;
	.data :
	{
		*(.data)

		. = ALIGN(16);

		__init_array_start = .;
		KEEP(*(.init_array*))
		__init_array_end = .;
	} :data
	_DATA_END = .;

	. = ALIGN(4096);

	_BSS_START = .;
	.bss : { *(.bss) }
	_BSS_END = .;

	. = ALIGN(4096);
	
	_IMAGE_END = . - 0xFFFFFFFF80000000;

	/DISCARD/ :
	{
		*(.comment)
	}
}

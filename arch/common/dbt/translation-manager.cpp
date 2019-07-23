/* SPDX-License-Identifier: MIT */

#include <dbt/translation-manager.h>
#include <dbt/translation.h>
#include <printf.h>

using namespace captive::arch::jit;

template<unsigned int RegionBits, unsigned int AlignmentBits>
TranslationManager<RegionBits, AlignmentBits>::TranslationManager()
{

}

template<unsigned int RegionBits, unsigned int AlignmentBits>
TranslationManager<RegionBits, AlignmentBits>::~TranslationManager()
{
	invalidate_all();
}

template<unsigned int RegionBits, unsigned int AlignmentBits>
bool TranslationManager<RegionBits, AlignmentBits>::invalidate_all()
{
	bool invalidated = false;
	for (const auto& region : _region_map) {
		invalidated |= region.value->invalidate_all();
	}

	return invalidated;
}

template<unsigned int RegionBits, unsigned int AlignmentBits>
bool TranslationManager<RegionBits, AlignmentBits>::invalidate_region(gpa_t pa)
{
	RegionContainer *rc;
	if (_region_map.try_get_value(pa_to_region_base(pa), rc)) {
		return rc->invalidate_all();
	} else {
		return false;
	}
}

template<unsigned int RegionBits, unsigned int AlignmentBits>
Translation* TranslationManager<RegionBits, AlignmentBits>::lookup_translation(gpa_t pa)
{
	RegionContainer *rc;
	if (!_region_map.try_get_value(pa_to_region_base(pa), rc)) {
		rc = new RegionContainer(*this);
		_region_map.add(pa_to_region_base(pa), rc);
	}

	return rc->lookup_translation(pa);
}

template<unsigned int RegionBits, unsigned int AlignmentBits>
void TranslationManager<RegionBits, AlignmentBits>::register_translation(gpa_t pa, Translation* txln)
{
	RegionContainer *rc;
	if (!_region_map.try_get_value(pa_to_region_base(pa), rc)) {
		rc = new RegionContainer(*this);
		_region_map.add(pa_to_region_base(pa), rc);
	}

	rc->register_translation(pa, txln);
}

template<unsigned int RegionBits, unsigned int AlignmentBits>
void TranslationManager<RegionBits, AlignmentBits>::add_garbage(Translation* txln)
{
	_destruction_queue.append(txln);
}

template<unsigned int RegionBits, unsigned int AlignmentBits>
void TranslationManager<RegionBits, AlignmentBits>::collect_garbage()
{
	for (auto txln : _destruction_queue) {
		delete txln;
	}

	_destruction_queue.clear();
}

template<unsigned int RegionBits, unsigned int AlignmentBits>
TranslationManager<RegionBits, AlignmentBits>::RegionContainer::RegionContainer(TranslationManager<RegionBits, AlignmentBits>& parent) : _parent(parent)
{
	/*for (auto& i : translation_bitmap_) {
		i = 0;
	}*/

	for (auto& i : translation_map_) {
		i = nullptr;
	}
}

template<unsigned int RegionBits, unsigned int AlignmentBits>
TranslationManager<RegionBits, AlignmentBits>::RegionContainer::~RegionContainer()
{
	invalidate_all();
}

template<unsigned int RegionBits, unsigned int AlignmentBits>
bool TranslationManager<RegionBits, AlignmentBits>::RegionContainer::invalidate_all()
{
	for (auto& i : translation_map_) {
		if (i != nullptr) {
			_parent.add_garbage(i);
			i = nullptr;
		}
	}

	return true;
}

template class TranslationManager<12u, 2u>;

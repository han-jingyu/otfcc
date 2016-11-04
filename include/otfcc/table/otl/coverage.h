#ifndef CARYLL_INCLUDE_TABLE_OTL_COVERAGE_H
#define CARYLL_INCLUDE_TABLE_OTL_COVERAGE_H
#include "../table-common.h"

typedef struct {
	glyphid_t numGlyphs;
	uint32_t capacity;
	otfcc_GlyphHandle *glyphs;
} otl_Coverage;

struct otfcc_CoveragePackage {
	otl_Coverage *(*create)();
	void (*clear)(otl_Coverage *coverage, uint32_t n);
	void (*dispose)(MOVE otl_Coverage *coverage);
	otl_Coverage *(*read)(const uint8_t *data, uint32_t tableLength, uint32_t offset);
	json_value *(*dump)(const otl_Coverage *coverage);
	otl_Coverage *(*parse)(const json_value *cov);
	caryll_Buffer *(*build)(const otl_Coverage *coverage);
	void (*shrink)(otl_Coverage *coverage, bool dosort);
	void (*push)(otl_Coverage *coverage, MOVE otfcc_GlyphHandle h);
};

extern const struct otfcc_CoveragePackage otfcc_pkgCoverage;

#endif

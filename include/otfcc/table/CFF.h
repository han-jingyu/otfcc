#ifndef CARYLL_INCLUDE_TABLE_CFF_H
#define CARYLL_INCLUDE_TABLE_CFF_H

#include "table-common.h"
#include "head.h"
#include "glyf.h"

typedef struct {
	double a;
	double b;
	double c;
	double d;
	double x;
	double y;
} cff_FontMatrix;

typedef struct {
	arity_t blueValuesCount;
	OWNING double *blueValues;
	arity_t otherBluesCount;
	OWNING double *otherBlues;
	arity_t familyBluesCount;
	OWNING double *familyBlues;
	arity_t familyOtherBluesCount;
	OWNING double *familyOtherBlues;
	double blueScale;
	double blueShift;
	double blueFuzz;
	double stdHW;
	double stdVW;
	arity_t stemSnapHCount;
	OWNING double *stemSnapH;
	arity_t stemSnapVCount;
	OWNING double *stemSnapV;
	bool forceBold;
	uint32_t languageGroup;
	double expansionFactor;
	double initialRandomSeed;
	double defaultWidthX;
	double nominalWidthX;
} cff_PrivateDict;

typedef struct _table_CFF table_CFF;

struct _table_CFF {
	// Name
	sds fontName;

	// General properties
	bool isCID;
	sds version;
	sds notice;
	sds copyright;
	sds fullName;
	sds familyName;
	sds weight;
	bool isFixedPitch;
	double italicAngle;
	double underlinePosition;
	double underlineThickness;
	double fontBBoxTop;
	double fontBBoxBottom;
	double fontBBoxLeft;
	double fontBBoxRight;
	double strokeWidth;
	OWNING cff_PrivateDict *privateDict;
	OWNING cff_FontMatrix *fontMatrix;

	// CID-only operators
	sds cidRegistry;
	sds cidOrdering;
	uint32_t cidSupplement;
	double cidFontVersion;
	double cidFontRevision;
	uint32_t cidCount;
	uint32_t UIDBase;
	// CID FDArray
	tableid_t fdArrayCount;
	OWNING table_CFF **fdArray;
};

// CFF and glyf
typedef struct {
	OWNING table_CFF *meta;
	OWNING table_glyf *glyphs;
} table_CFFAndGlyf;

table_CFF *table_new_CFF();
void table_delete_CFF(MOVE table_CFF *table);
table_CFFAndGlyf table_read_cff_and_glyf(const caryll_Packet packet, const otfcc_Options *options,
                                         const table_head *head);
void table_dump_cff(const table_CFF *table, MODIFY json_value *root, const otfcc_Options *options);
table_CFF *table_parse_cff(json_value *root, const otfcc_Options *options);
caryll_Buffer *table_build_CFF(const table_CFFAndGlyf cffAndGlyf, const otfcc_Options *options);

#endif

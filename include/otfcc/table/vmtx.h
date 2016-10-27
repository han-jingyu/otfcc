#ifndef CARYLL_INCLUDE_TABLE_VMTX_H
#define CARYLL_INCLUDE_TABLE_VMTX_H

#include "table-common.h"

#include "vhea.h"
#include "maxp.h"

typedef struct {
	length_t advanceHeight;
	pos_t tsb;
} vertical_metric;

typedef struct {
	vertical_metric *metrics;
	pos_t *topSideBearing;
} table_vmtx;

void table_delete_vmtx(MOVE table_vmtx *table);
table_vmtx *table_read_vmtx(const caryll_Packet packet, const otfcc_Options *options, table_vhea *vhea,
                            table_maxp *maxp);
caryll_Buffer *table_build_vmtx(const table_vmtx *table, glyphid_t count_a, glyphid_t count_k,
                                const otfcc_Options *options);

#endif

// Distributed under the MIT software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.
// Based on the public domain XMSS reference implementation
// by Andreas Hülsing and Joost Rijneveld

#ifndef XMSS_PARAMS_H
#define XMSS_PARAMS_H

#include <cstdint>
#include "wots.h"

// TODO: remove this if possible. use a context struct?

#define XMSS_PARAM_MAX_h 4
#define XMSS_PARAM_MAX_k 2
/*
SIGNATURE_BASE_SIZE = calculateSignatureBaseSize(wotsParamW) = 4 + 32 + wotsParams.keysize;
height = (sigSize - SIGNATURE_BASE_SIZE)/32;
*/

typedef struct {
    wots_params wots_par;
    uint32_t n;
    uint32_t h;
    uint32_t k;
} xmss_params;

#endif // XMSS_PARAMS_H

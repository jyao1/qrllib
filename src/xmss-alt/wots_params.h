#ifndef WOTS_PARAMS_H
#define WOTS_PARAMS_H

#define XMSS_PARAM_MAX_n           32
#define XMSS_PARAM_MAX_w           16
#define XMSS_PARAM_MAX_log_w       4
#define XMSS_PARAM_MAX_len1        64
#define XMSS_PARAM_MAX_len2        4
#define XMSS_PARAM_MAX_len         (XMSS_PARAM_MAX_len1 + XMSS_PARAM_MAX_len2)
#define XMSS_PARAM_MAX_keysize     (XMSS_PARAM_MAX_len * XMSS_PARAM_MAX_n)
/*
    params->n = n;
    params->w = w;
    params->log_w = (int) log2(w);
    params->len_1 = (int) ceil(((8 * n) / params->log_w));
    params->len_2 = (int) floor(log2(params->len_1 * (w - 1)) / params->log_w) + 1;
    params->len = params->len_1 + params->len_2;
    params->keysize = params->len * params->n;
*/
/**
 * WOTS parameter set
 *
 * Meaning as defined in draft-irtf-cfrg-xmss-hash-based-signatures-02
 */
// FIXME: Get rid of this
typedef struct {
    uint32_t len_1;
    uint32_t len_2;
    uint32_t len;
    uint32_t n;
    uint32_t w;
    uint32_t log_w;
    uint32_t keysize;
} wots_params;

/**
 * Set the WOTS parameters,
 * only m, n, w are required as inputs,
 * len, len_1, and len_2 are computed from those.
 *
 * Assumes w is a power of 2
 */
void wots_set_params(wots_params *params, int n, int w);

#endif
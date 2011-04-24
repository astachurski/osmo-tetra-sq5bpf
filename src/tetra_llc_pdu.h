#ifndef TETRA_LLC_PDU_H
#define TETRA_LLC_PDU_H

/* Table 21.1 */
enum tetra_llc_pdu_t {
	TLLC_PDUT_BL_ADATA		= 0,
	TLLC_PDUT_BL_DATA		= 1,
	TLLC_PDUT_BL_UDATA		= 2,
	TLLC_PDUT_BL_ACK		= 3,
	TLLC_PDUT_BL_ADATA_FCS		= 4,
	TLLC_PDUT_BL_DATA_FCS		= 5,
	TLLC_PDUT_BL_UDATA_FCS		= 6,
	TLLC_PDUT_BL_ACK_FCS		= 7,
	TLLC_PDUT_AL_SETUP		= 8,
	TLLC_PDUT_AL_DATA_FINAL		= 9,
	TLLC_PDUT_AL_UDATA_UFINAL	= 10,
	TLLC_PDUT_AL_ACK_RNR		= 11,
	TLLC_PDUT_AL_RECONNECT		= 12,
	TLLC_PDUT_SUPPL			= 13,
	TLLC_PDUT_L2SIG			= 14,
	TLLD_PDUT_AL_DISC		= 15
};
const char *tetra_get_llc_pdut_name(uint8_t pdut);

/* Table 21.2 */
enum tetra_llc_l2sig_pdu_t {
	TLLC_PDUT_L2_DATA_PRIO		= 0,
	TLLC_PDUT_L2_SCHEDULE_SYNC	= 1,
	TLLC_PDUT_L2_LINK_FB_CTRL	= 2,
	TLLC_PDUT_L2_LINK_FB_INFO	= 3,
	TLLC_PDUT_L2_LINK_FB_INFO_RD_PRIO = 4
};

/* Table 21.3 */
enum tetra_llc_suppl_pdu_t {
	TLLC_PDUT_SUPPL_ALX_DATA_FINAL	= 0,
	TLLC_PDUT_SUPPL_ALX_UDATA_UFINAL = 1,
	TLLC_PDUT_SUPPL_ALX_ACK_RNR	= 2
};

/* Decoded */

enum tllc_pdut_dec {
	TLLC_PDUT_DEC_UNKNOWN,
	TLLC_PDUT_DEC_BL_ADATA,
	TLLC_PDUT_DEC_BL_DATA,
	TLLC_PDUT_DEC_BL_UDATA,
	TLLC_PDUT_DEC_BL_ACK,
	TLLC_PDUT_DEC_AL_SETUP,
	TLLC_PDUT_DEC_AL_DATA,
	TLLC_PDUT_DEC_AL_FINAL,
	TLLC_PDUT_DEC_AL_UDATA,
	TLLC_PDUT_DEC_AL_UFINAL,
	TLLC_PDUT_DEC_AL_ACK,
	TLLC_PDUT_DEC_AL_RNR,
	TLLC_PDUT_DEC_AL_RECONNECT,
	TLLC_PDUT_DEC_AL_DISC,
	TLLC_PDUT_DEC_ALX_DATA,
	TLLC_PDUT_DEC_ALX_FINAL,
	TLLC_PDUT_DEC_ALX_UDATA,
	TLLC_PDUT_DEC_ALX_UFINAL,
	TLLC_PDUT_DEC_ALX_ACK,
	TLLC_PDUT_DEC_ALX_RNR,
};
const char *tetra_get_llc_pdut_dec_name(enum tllc_pdut_dec pdut);

struct tetra_llc_pdu {
	enum tllc_pdut_dec pdu_type;
	uint8_t nr;
	uint8_t ns;
	uint8_t ss;
	uint32_t _fcs;
	uint32_t *fcs;
	uint8_t *tl_sdu;	/* pointer to bitbuf */
	uint8_t tl_sdu_len;	/* in bits */
};

int tetra_llc_pdu_parse(struct tetra_llc_pdu *lpp, uint8_t *buf, int len);

#endif /* TETRA_LLC_PDU_H */

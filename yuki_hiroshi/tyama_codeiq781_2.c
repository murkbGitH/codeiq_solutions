//gcc -O3 tyama_codeiq781_1.c tyama_codeiq781_2_sha1.c

#include <stdio.h>
#include <string.h>

//#include "sha1.h"
#include <stdint.h>
struct sha1_ctxt {
	union {
		uint8_t	b8[20];
		uint32_t	b32[5];
	} h;
	union {
		uint8_t	b8[8];
		uint64_t	b64[1];
	} c;
	union {
		uint8_t	b8[64];
		uint32_t	b32[16];
	} m;
	uint8_t	count;
};
void sha1_init(struct sha1_ctxt *ctxt);
void sha1_loop(struct sha1_ctxt *ctxt,const uint8_t *input,size_t len);
void sha1_result(struct sha1_ctxt *ctxt,uint8_t *digest);

unsigned char data[]={0xc8,0xee,0xa8,0x0f,0x80,0xfd,0x60,0xe9,0x00,0x3f,0xc4,0xb0,0x10,0x2c,0xe7,0x33,0xdc,0x82,0x1e,0x6b,0xd3,0x5b,0xbb,0xfa,0x8a,0x48,0xc2,0xf0,0x97,0x7f,0xa6,0xc0,0x9c,0x32,0x15,0x89,0x37,0x51,0xaa,0xc9,0xd8,0x93,0x9d,0x86,0xda,0x28,0xbb,0x58,0xa2,0x6d,0xe2,0x7f,0x3a,0x3b,0xa5,0xf1,0xa5,0x31,0x89,0x6c,0xd8,0xb5,0xe6,0x15,0xbc,0xa4,0xbc,0x59,0x93,0xcd,0x68,0x85,0x52,0x48,0x93,0x36,0xb1,0xf4,0x5e,0xfa,0xd1,0x62,0x7c,0x4b,0xc1,0xa2,0xe4,0x98,0x7f,0x17,0xd5,0x21,0x37,0x7f,0xc5,0xa0,0x2c,0xbe,0x67,0x4d,0xdc,0x5a,0x0b,0x66,0xd9,0xd4,0x5b,0x09,0x58,0x2f,0x72,0xed,0x4f,0x45,0x81,0x36,0x73,0xab,0x18,0xdf,0x51,0x5c,0x1a,0xd3,0x7f,0x2e,0xef,0xb8,0xd8,0xc8,0xc0,0x8a,0x4c,0xba,0x87,0x23,0x01,0x44,0x46,0xe7,0x03,0x42,0xef,0x44,0xea,0x05,0x36,0x11,0x3c,0x03,0x67,0x24,0xa4,0xbc,0x53,0xef,0x6e,0x2d,0xc3,0x66,0xb9,0xcf,0x9c,0xc2,0x55,0x04,0x9c,0xf8,0xf4,0x99,0xb8,0xaf,0xff,0xea,0x16,0x7d,0xaa,0xec,0xff,0x7d,0xe2,0x52,0x8b,0xb7,0x65,0xee,0x2c,0x69,0x07,0x1d,0xd9,0x14,0xc5,0x5a,0x6b,0x5a,0xbc,0xef,0x34,0x12,0xc4,0x0d,0x7d,0x4e,0xaa,0xdd,0x19,0x0a,0x2b,0x5f,0x8b,0xce,0x06,0x2d,0xa0,0x6c,0x76,0x49,0xe2,0x62,0xac,0x4b,0x04,0x46,0xfa,0xe6,0x58,0x3e,0xd0,0x7b,0x58,0xf0,0x8a,0x9e,0x67,0x1b,0x96,0x3c,0xb3,0x93,0x94,0x66,0x8a,0x44,0x50,0xd5,0x4f,0xf8,0x49,0x33,0x4e,0xba,0xca,0xe1,0x95,0x24,0x92,0x43,0x85,0xfc,0xa8,0xb1,0x66,0x6f,0x46,0x57,0xbd,0xa5,0xb3,0x1e,0x1b,0x47,0x5b,0x95,0xeb,0xe7,0x8c,0x41,0x25,0xdc,0x88,0x9d,0x66,0x72,0x36,0x6b,0xc1,0xd8,0xe8,0x60,0x59,0xba,0x1f,0xbd,0x66,0xa7,0x3c,0xa3,0x1d,0x08,0xde,0xcf,0xeb,0x02,0x10,0x90,0xfd,0x9a,0xf9,0x51,0x83,0x6c,0x22,0x79,0x6f,0x79,0xd7,0x98,0x52,0x43,0xdd,0x1e,0x66,0xab,0xe1,0xf0,0xe2,0xe4,0x85,0x0d,0x5f,0xe5,0xb9,0x83,0x07,0xe0,0x84,0x9c,0xb8,0x3a,0x60,0x1e,0x00,0x31,0x8b,0xe9,0x7b,0x9b,0x6e,0x56,0xf0,0x84,0x81,0xa7,0xae,0xae,0xbe,0xb2,0x56,0x0a,0xc3,0xb8,0xde,0xb8,0x5c,0x8a,0x09,0x83,0x4c,0x9f,0x12,0xd3,0xde,0xc2,0x08,0xf2,0x79,0xcf,0x71,0x51,0xb3,0xe5,0xf0,0xd2,0x47,0x12,0x0e,0xdf,0x98,0xb2,0x5c,0x02,0xe7,0xe3,0x4d,0xb3,0x6b,0x20,0x91,0x0d,0x7c,0x0e,0xe2,0x95,0x2e,0x7a,0x29,0xe2,0x7c,0xc0,0xa8,0x9a,0xb6,0x25,0xc1,0xfb,0xe5,0xeb,0xa5,0xa0,0xf6,0xe2,0xe6,0xa0,0x70,0x4e,0xe5,0x8f,0xde,0x1e,0x9c,0x33,0x29,0x2f,0xda,0x85,0xe0,0x9a,0xc2,0xf6,0x6f,0x71,0xa9,0x84,0xe7,0xf9,0x61,0x29,0x50,0x3a,0x0a,0x65,0xc3,0xbd,0x91,0xcc,0x7e,0x52,0x69,0x84,0x12,0x27,0x6c,0x97,0x0c,0x9c,0xfc,0x60,0x32,0x58,0x7d,0xbd,0x2e,0x4f,0x5a,0x36,0x97,0xed,0x34,0x5a,0x35,0x2f,0xa8,0xed,0xdc,0xa0,0x67,0xf0,0xfe,0x17,0xc9,0xe0,0x6e,0xd6,0xd1,0x9d,0x58,0xc2,0xe0,0x81,0x6f,0xc1,0x7f,0xe9,0x38,0x5c,0xec,0x5a,0x30,0x08,0x00,0xcb,0xc3,0x65,0x2f,0xa9,0x78,0x6d,0xf5,0xc0,0xd1,0x34,0x8e,0x99,0xc8,0x52,0x85,0xe4,0xf7,0x06,0xfd,0xe7,0x1b,0x14,0x9f,0x97,0xbd,0xd9,0x97,0x29,0x18,0x8a,0x2a,0xe4,0x76,0xaa,0x36,0x2d,0xce,0x4e,0xe4,0xd0,0x84,0x69,0x65,0x22,0x0c,0x9b,0xa4,0x42};

int main(){
	const int l=sizeof(data);
	int i,seed=234; ///
	unsigned char buf[l+1],digest[20],c;

	struct sha1_ctxt sha1ctx,sha1ctx2;
	for(seed=128;seed<256;seed++){
		sha1_init(&sha1ctx);
		c=seed;
		for(i=0;i<l;i++){
			buf[i]=data[i]^c;
			if(buf[i]<32||127<buf[i])break;
			sha1_loop(&sha1ctx,&c,1);
#if 1
			memcpy(&sha1ctx2,&sha1ctx,sizeof(struct sha1_ctxt));
			sha1_result(&sha1ctx2,digest);
#else
			sha1_result(&sha1ctx,digest);
#endif
			c=digest[19];
		}
		if(i==l){
			buf[l]=0;
			puts(buf);
			break;
		}
	}
	if(seed==256){
		puts("No luck.");
	}
	return 0;
}
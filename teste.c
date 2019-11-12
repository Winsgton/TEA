#include <stdint.h>
#include <stdio.h> // a libc vai definir essas funções
// encryption routine 

// encryption routine
void encrypt (uint32_t* v, uint32_t* k) {
 uint32_t v0=v[0], v1=v[1], sum=0, i;
 printf("teste %X\n teste 2 %X", v0, v1);
 uint32_t delta=0x9e3779b9;
 uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];
 printf("\n\ntesteeee %X\n testeeeeeeeeeeeeeeeee 2 %X\n test %X\n te %X", k0, k1, k2, k3);
 for (i=0; i < 32; i++) {
 sum += delta;
 v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
 v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
 }
 v[0]=v0; v[1]=v1;
}

// decryption routine
void decrypt (uint32_t* v, uint32_t* k) {
 uint32_t v0=v[0], v1=v[1], sum=0xC6EF3720, i;
 uint32_t delta=0x9e3779b9;
 uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];
 for (i=0; i<32; i++) {
 v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
 v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
 sum -= delta;
 }
 v[0]=v0; v[1]=v1;
}



int main() {
  ///uint32_t  *v;
 // v = 0x0123456789abcdef;
 // uint32_t  *k ;
  //k = 0x00112233445566778899aabbccddeeff;
  
  
  		//uint32_t v[] = {0xFFFFFFFF, 0xFFFFFFFF};
	
		 uint32_t v[] = {0x01234567, 0x89abcdef}; //#Eg?«Íï 
		 //uint32_t v[] = {'0x01234567', '0x89abcdef'};
		 uint32_t k[] = {0x00112233, 0x44556677, 0x8899aabb, 0xccddeeff}; //"3DUfw??ª»ÌÝîÿ
		// 64 bit ASCII->HEX translation of LJBLKECB: 4C4A424C4B454342  
		// 64 bit ASCII->HEX trnaslation of 0CELCIMF: 3043454C43494D46
			
  
  		printf("PRINTANDO VALOR DO PONTEIRO V: %c \n", v[3]);
  
 		printf(" Original Values: ");
		printf("[ %X %X %x %d]", v[0], v[1], v, &v);
		
        encrypt(v, k);

        printf("\n Encrypted:       ");
        printf("[ %X %X %x %d]", v[0], v[1], v, &v);

        decrypt(v, k);
        printf("\n Decrypted:       ");
        printf("[ %X %X %x %d]", v[0], v[1], v, &v);
        printf("\n");
}

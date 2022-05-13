#include<stdio.h>
unsigned int getbit(unsigned K1, int i)
//get ith bit from left to right
{
	unsigned int b = K1 >> (32 - i);
	unsigned bit = b & 0x01;
	return bit;
}

unsigned int getbit28(unsigned K1, int i)
//get ith bit from left to right
{
	unsigned int b = K1 >> (28 - i);
	unsigned bit = b & 0x01;
	return bit;
}

unsigned int PC1CD(unsigned int K1, unsigned int K2, int chiso1, int chiso2)
{
	int pc1[] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};
	unsigned int pc1k1 = 0;
	for(int i = chiso1; i < chiso2; i++)
	{
		int vitri;
		unsigned int bit;
		if(pc1[i] > 32)
		{
			
		}	
		else 
		{
			
		}
		unsigned b = bit & 0x01;
		pc1k1 = (pc1k1 << 1) | b;
	}
	return pc1k1;
}
unsigned int ShiftLeft(unsigned int C0, int s)
{
	unsigned int C1;
	unsigned int sbit, bit28s;

	C1 = bit28s | sbit;
	return C1;
}
unsigned int KPC2(unsigned int C1, unsigned int D1, int chiso1, int chiso2)
{
	int pc2[] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
	unsigned int pc2k = 0;
	for(int i = chiso1; i < chiso2; i++)
	{
		int vitri;
		unsigned int bit;

		unsigned b = bit & 0x01;
		pc2k = (pc2k << 1) | b;
	}
	return pc2k;
}

void GenKey(unsigned int K1, unsigned int K2, unsigned int key1[16], unsigned int key2[16])
{
	unsigned int C0, D0;
	C0 = PC1CD(K1,K2,0,28);
	D0 = PC1CD(K1,K2,28,56);
	int s[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
	unsigned int C1, D1;
	for(int i = 0; i < 16; i++)
	{

		C0 = C1; D0 = D1;	
	}
}

unsigned int IPM(unsigned int M1, unsigned int M2, int chiso1, int chiso2)
{
	int IP[] = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3,61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
	unsigned int ipm1 = 0;
	for(int i = chiso1; i < chiso2; i++)
	{
		int vitri;
		unsigned int bit;
		if(IP[i] > 32)
		{

		}	
		else 
		{

		}
		unsigned b = bit & 0x01;
		ipm1 = (ipm1 << 1) | b;
	}
	return ipm1;
}

unsigned int ER0(unsigned int R0, int chiso1, int chiso2)
{
	int E[] = {32 , 1 , 2 , 3 , 4 , 5, 4 , 5 , 6 , 7 , 8 , 9, 8 , 9 , 10 , 11 , 12 , 13, 12 , 13 , 14 , 15 , 16 , 17, 16 , 17 , 18 , 19 , 20 , 21, 20 , 21 , 22 , 23 , 24 , 25, 24 , 25 , 26 , 27 , 28 , 29, 28 , 29 , 30 , 31 , 32 , 1 };
	unsigned int er1 = 0;
	for(int i = chiso1; i < chiso2; i++)
	{
		int vitri;
		unsigned int bit;
	    vitri = E[i];
	    bit = getbit(R0,vitri);
		unsigned b = bit & 0x01;
		er1 = (er1 << 1) | b;
	}
	return er1;
}

unsigned int SubByte(unsigned int A1, unsigned int A2)
{
	int S1[] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7, 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8, 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0, 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13} ;
	int S2[] = {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10, 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5, 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15, 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9} ;
	int S3[] = {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8, 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1, 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7, 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12};
	int S4[] = {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15, 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9, 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4, 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14};
	int S5[] = {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3};
	int S6[] = {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11, 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13};
	int S7[] ={ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1, 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6, 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12};
	int S8[] = { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7, 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};
	unsigned int B;
	int chiso[9];
	int S[9];
	//4 cap 6 bit ben trai thuoc A1
	for(int i = 1; i <= 4; i++)
	{
		unsigned int b6i = (A1 >> (24 - 6*i)) & 0x3F;
		int bit1 = (b6i >> 5) & 0x01;
		int bit6 = b6i & 0x01;


	}
	//4 cap 6 bit ben phai thuoc A2
	for(int i = 5; i <= 8; i++)
	{
		unsigned int b6i = (A2 >> (24 - 6*(i-4))) & 0x3F;
		int bit1 = (b6i >> 5) & 0x01;
		int bit6 = b6i & 0x01;


	}
	//Tra bang S
	S[1] = S1[chiso[1]]; S[2] = S2[chiso[2]];
	S[3] = S3[chiso[3]]; S[4] = S4[chiso[4]];
	S[5] = S5[chiso[5]]; S[6] = S6[chiso[6]];
	S[7] = S7[chiso[7]]; S[8] = S8[chiso[8]];
	//Ghep 8 cap 4 bit tao thanh B (32 bit)
	B = 0;
	for(int i = 1; i <= 8; i++)
	    B = (B << 4) | S[i];
	return B;
}

unsigned int HoanviP(unsigned int B)
{
	int P[] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};
	unsigned int fp = 0;
	for(int i = 0; i < 32; i++)
	{
		int vitri;
		unsigned int bit;
	    vitri = P[i];
	    bit = getbit(B,vitri);
		unsigned b = bit & 0x01;
		fp = (fp << 1) | b;
	}
	return fp;
}

unsigned int F(unsigned int L0, unsigned int R0, unsigned int key1, unsigned int key2)
{
	//Buoc 4. Mo rong nua phai R0
	unsigned int ER01, ER02;


	//Buoc 5. phép XOR, tính A = E[R0] + K1.
	unsigned int A1, A2;
	A1 = key1 ^ ER01;
	A2 = key2 ^ ER02;
	//Buoc 6&7. B3: B = S1(A1) S2(A2) S3(A3) S4(A4) S5(A5) S6(A6) S7(A7) S8(A8)
	unsigned int B;
	B = SubByte(A1, A2);
	//Buoc 8: Hoan vi P
	unsigned int FP;
	FP = HoanviP(B);
	return FP;
}

unsigned int HoanviIP_1(unsigned int M1, unsigned int M2, int chiso1, int chiso2)
{
	int IP1[] =  {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};
	unsigned int ipm1 = 0;
	for(int i = chiso1; i < chiso2; i++)
	{
		int vitri;
		unsigned int bit;
		if(IP1[i] > 32)
		{


		}	
		else 
		{


		}
		unsigned b = bit & 0x01;
		ipm1 = (ipm1 << 1) | b;
	}
	return ipm1;
}

void ShowByte(unsigned int C)
{
	for(int i = 1; i <= 8; i++)
	{
		unsigned int b = (C >> (32 - 4*i)) & 0xF;
		printf("%X", b);
	}
}

void MahoaDES(unsigned int M1, unsigned int M2, unsigned int K1, unsigned int K2, unsigned int &C1, unsigned int &C2)
{
	unsigned int key1[16];
	unsigned int key2[16];
	GenKey(K1,K2,key1,key2);
	//Buoc 3. Thuc hien hoan vi IP
	unsigned int L0,R0;
	L0 = IPM(M1, M2, 0, 32);
	R0 = IPM(M1, M2, 32, 64);
	unsigned int L1, R1;
	unsigned int FP;
	for(int i = 0; i < 16; i++)
	{




	}
	C1 = HoanviIP_1(R1,L1,0,32);
	C2 = HoanviIP_1(R1,L1,32,64);
}

void GiaiMaDES(unsigned int M1, unsigned int M2, unsigned int K1, unsigned int K2, unsigned int &C1, unsigned int &C2)
{
	unsigned int key1[16];
	unsigned int key2[16];
	GenKey(K1,K2,key1,key2);
	//Buoc 3. Thuc hien hoan vi IP
	unsigned int L0,R0;
	L0 = IPM(M1, M2, 0, 32);
	R0 = IPM(M1, M2, 32, 64);
	unsigned int L1, R1;
	unsigned int FP;
	for(int i = 0; i < 16; i++)
	{


	}
	C1 = HoanviIP_1(R1,L1,0,32);
	C2 = HoanviIP_1(R1,L1,32,64);
}

int main()
{
	unsigned int K1 = 0x13345779; //4byte
	unsigned int K2 = 0x9BBCDFF1;
	printf("\nKhoa K = "); ShowByte(K1); ShowByte(K2);
	unsigned int M1 = 0x01234567;
	unsigned int M2 = 0x89ABCDEF;
	printf("\nBan tin M = "); ShowByte(M1); ShowByte(M2);
	unsigned int C1, C2;
	MahoaDES(M1, M2, K1, K2, C1, C2);
	printf("\nBan ma C = "); ShowByte(C1); ShowByte(C2);
	unsigned int MC1, MC2;
	GiaiMaDES(C1, C2, K1, K2, MC1, MC2);
	printf("\nBan Giai ma MC = "); ShowByte(MC1); ShowByte(MC2);	
}

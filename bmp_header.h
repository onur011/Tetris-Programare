#pragma pack(1)                //CD 311 Veis Onur Șener

//strucuri specifice fisierelor .bmp

typedef struct
{
    unsigned char  fileMarker1; // 'B' 
    unsigned char  fileMarker2; // 'M' 
    unsigned int   bfSize;      //dimensiunea intregului fisier
    unsigned short unused1;     // = 0;
    unsigned short unused2;     // = 0;
    unsigned int   imageDataOffset; //offsetul de la inceputul fisierului 
    //pana la inceputului bitmap-ului, adica al matricii de pixeli.
} bmp_fileheader;

typedef struct 
{
    unsigned int   biSize;          // = 40; dimensiune info header
    signed int     width;           // latimea matrice de pixeli
    signed int     height;          // inaltimea matricei de pixeli
    unsigned short planes;          // = 1;
    unsigned short bitPix;          // = 24; numarul de biti per pixel
    unsigned int   biCompression;   // = 0;
    unsigned int   biSizeImage;     //dimensiunea matricii de pixeli
    int            biXPelsPerMeter; // = 0; rezolutie de printare
    int            biYPelsPerMeter; // = 0; rezolutie de printare
    unsigned int   biClrUsed;       // = 0; 
    unsigned int   biClrImportant;  // = 0;numarul de culori importante
}bmp_infoheader;

typedef struct
{
    unsigned char b;
    unsigned char g;
    unsigned char r; 
} Pixel;

typedef struct {
    bmp_fileheader bmp_fileheader;
    bmp_infoheader bmp_infoheader;
} bmp;

#pragma pack()

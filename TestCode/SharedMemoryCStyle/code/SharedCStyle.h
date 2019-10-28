#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

typedef void* mylibrary_mytype_t;

EXTERNC mylibrary_mytype_t mylibrary_mytype_init();
EXTERNC void mylibrary_mytype_destroy(mylibrary_mytype_t mytype);
EXTERNC void mylibrary_mytype_doit(mylibrary_mytype_t self, int param);
EXTERNC void mylibrary_avframe2cvmat(int height, int width, char* data, int linesize);
EXTERNC unsigned char* get_cvmat_ptr(int w, int h);
EXTERNC void create_shm();

#undef EXTERNC
typedef struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  const unsigned char	 pixel_data[8 * 8 * 4 + 1];
} gimp_image;

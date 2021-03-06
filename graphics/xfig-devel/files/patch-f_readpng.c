--- f_readpng.c.orig
+++ f_readpng.c
@@ -73,7 +73,7 @@ read_png(FILE *file, int filetype, F_pic
     }
 
     /* set long jump recovery here */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* if we get here there was a problem reading the file */
 	png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
 	close_picfile(file,filetype);
@@ -90,15 +90,17 @@ read_png(FILE *file, int filetype, F_pic
     png_get_IHDR(png_ptr, info_ptr, &w, &h, &bit_depth, &color_type,
 	&interlace_type, &compression_type, &filter_type);
 
-    if (info_ptr->valid & PNG_INFO_gAMA)
-	png_set_gamma(png_ptr, 2.2, info_ptr->gamma);
-    else
-	png_set_gamma(png_ptr, 2.2, 0.45);
+    png_fixed_point gamma = 0.45;
+    png_get_gAMA_fixed(png_ptr,info_ptr,&gamma);
+    png_set_gamma(png_ptr, 2.2, gamma);
 
-    if (info_ptr->valid & PNG_INFO_bKGD)
+    if (png_get_valid(png_ptr,info_ptr,PNG_INFO_bKGD)) {
 	/* set the background to the one supplied */
-	png_set_background(png_ptr, &info_ptr->background,
+	png_color_16p background;
+	png_get_bKGD(png_ptr,info_ptr,&background);
+	png_set_background(png_ptr, background,
 		PNG_BACKGROUND_GAMMA_FILE, 1, 1.0);
+    }
     else {
 	/* blend the canvas background using the alpha channel */
 	background.red   = x_bg_color.red >> 8;
@@ -136,7 +138,11 @@ read_png(FILE *file, int filetype, F_pic
 
 	if (png_get_PLTE(png_ptr, info_ptr, &palette, &num_palette)) {
 	    png_get_hIST(png_ptr, info_ptr, &histogram);
+#if PNG_LIBPNG_VER_MAJOR <= 1 && PNG_LIBPNG_VER_MINOR < 5
 	    png_set_dither(png_ptr, palette, num_palette, 256, histogram, 0);
+#else
+	    png_set_quantize(png_ptr, palette, num_palette, 256, histogram, 0);
+#endif
 	}
     }
     if (color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA) {

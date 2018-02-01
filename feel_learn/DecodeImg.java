package com.albertd.feel_learn;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

/**
 * Created by AlbertD on 04/12/2017.
 */

public class DecodeImg {

	public DecodeImg(){

	}

	public Bitmap decodeFileToBitmap(String path, int size){//File file) {
		// BitmapFactory options to downsize the image
		BitmapFactory.Options o = new BitmapFactory.Options();
		o.inJustDecodeBounds = true;
		o.inSampleSize = 4;

		// Decode image size
		//BitmapFactory.decodeStream(new FileInputStream(file), null, o);
		BitmapFactory.decodeFile(path, o);

		// The new size we want to scale to
		final int REQUIRED_SIZE = size;

		// Find the correct scale value. It should be the power of 2.
		int imgHeight = o.outHeight;
		int imgWidth = o.outWidth;
		int inSampleSize = 1;
		if (imgHeight > REQUIRED_SIZE || imgWidth > REQUIRED_SIZE) {
			final int halfHeight = imgHeight / 2;
			final int halfWidth = imgWidth / 2;
			// Calculate the largest inSampleSize value that is a power of 2 and keeps both
			// height and width larger than the requested height and width.
			while((halfHeight/inSampleSize) >= REQUIRED_SIZE && (halfWidth/inSampleSize) >= REQUIRED_SIZE) {
				inSampleSize *= 2;
			}
		}

		// Decode with inSampleSize
		//BitmapFactory.Options o2 = new BitmapFactory.Options();
		o.inJustDecodeBounds = false;
		//o2.inSampleSize = inSampleSize;
		return BitmapFactory.decodeFile(path, o); //BitmapFactory.decodeStream(new FileInputStream(file), null, o2);

		// here i override the original image file
		//File file2 = file;
		//file.createNewFile();
		//FileOutputStream outputStream = new FileOutputStream(file);

		//selectedBitmap.compress(Bitmap.CompressFormat.JPEG, 90 , outputStream);

		//return file;
	}
}

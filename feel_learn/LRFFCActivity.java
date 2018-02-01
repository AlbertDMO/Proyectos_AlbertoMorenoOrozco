package com.albertd.feel_learn;

import android.os.Bundle;
import android.os.Environment;
import android.widget.ImageView;
import android.widget.TableLayout;

import java.io.File;

/**
 * Created by AlbertD on 04/12/2017.
 */

public class LRFFCActivity extends FeelLearn{

	File storage, dir;
	String [] nombres;

	ImageView img1, img2, img3, img4;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.lrffcseleccion_screen);
		preferencias = getSharedPreferences(PREFERENCIAS, MODE_PRIVATE);

		storage = Environment.getExternalStorageDirectory();
		dir = new File(storage.getAbsolutePath() + "/datos/IMG_20151002_162535292_HDR.jpg");

		DecodeImg dimg = new DecodeImg();

		img1 = (ImageView) findViewById(R.id.lrffc_img1);
		img2 = (ImageView) findViewById(R.id.lrffc_img2);
		img3 = (ImageView) findViewById(R.id.lrffc_img3);
		img4 = (ImageView) findViewById(R.id.lrffc_img4);

		img1.setImageBitmap(dimg.decodeFileToBitmap(dir.getAbsolutePath(), 150));
		img2.setImageResource(R.drawable.rompecabeza_base);
		img3.setImageResource(R.drawable.rompecabeza_base);
		img4.setImageResource(R.drawable.rompecabeza_base);
	}
}

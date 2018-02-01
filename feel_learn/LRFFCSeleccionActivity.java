package com.albertd.feel_learn;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.GridLayout;
import android.widget.ImageView;
import android.widget.TableLayout;

/**
 * Created by AlbertD on 30/11/2017.
 */

public class LRFFCSeleccionActivity extends FeelLearn {

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.lrffcseleccion_screen);
		GridLayout gdl = (GridLayout) findViewById(R.id.LRFFC_Select);

		ImageView img = (ImageView) findViewById(R.id.select_img);

		//preferencias = getSharedPreferences(PREFERENCIAS, MODE_PRIVATE);
		//int nivel = preferencias.getInt(NIVEL, 1);

		img.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View view) {
				Intent intent = new Intent(LRFFCSeleccionActivity.this, LRFFCActivity.class);
				startActivity(intent);
			}
		});
	}
}

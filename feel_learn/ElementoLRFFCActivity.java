package com.albertd.feel_learn;

import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

/**
 * Created by AlbertD on 29/11/2017.
 */

public class ElementoLRFFCActivity extends FeelLearn{

	EditText nombreET, car1ET, car2ET;
	ImageView img;
	Button btn;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.elementolrffc_screen);
		getSupportActionBar().setDisplayHomeAsUpEnabled(true);
		String titulo = getIntent().getStringExtra("Titulo");
		getSupportActionBar().setTitle(titulo);

		nombreET = (EditText) findViewById(R.id.elto_nombre);
		car1ET = (EditText) findViewById(R.id.elto_car1);
		car2ET = (EditText) findViewById(R.id.elto_car2);
		img = (ImageView) findViewById(R.id.elto_img);
		btn = (Button) findViewById(R.id.elto_button);

		if (titulo.equals("Editar elemento LRFFC")){
			String nombre = getIntent().getStringExtra("Nombre");
			String path = getIntent().getStringExtra("Path");
			//car 1
			//car 2
			nombreET.setText(nombre);
			DecodeImg dimg = new DecodeImg();
			img.setImageBitmap(dimg.decodeFileToBitmap(path, 100));
		}

		img.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View view) {

			}
		});

		btn.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View view) {

			}
		});
	}
}

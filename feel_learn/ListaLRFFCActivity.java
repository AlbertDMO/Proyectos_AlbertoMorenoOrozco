package com.albertd.feel_learn;

import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.Environment;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by AlbertD on 23/11/2017.
 */



public class ListaLRFFCActivity extends FeelLearn {

	File storage, dir;
	String [] nombres;
	File [] imgf;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.listalrffc_screen);
		getSupportActionBar().setDisplayHomeAsUpEnabled(true);

		FloatingActionButton add = (FloatingActionButton) findViewById(R.id.addButton);

		storage = Environment.getExternalStorageDirectory();
		dir = new File(storage.getAbsolutePath() + "/datos");

		DecodeImg dimg = new DecodeImg();

		final ArrayList<Bitmap> img = new ArrayList<Bitmap>();
		nombres = dir.list();
		imgf = dir.listFiles();
		int size = 80;

		for (int i = 0; i < imgf.length; i++) {
			img.add(dimg.decodeFileToBitmap(imgf[i].getAbsolutePath(), size));
		}

		ListView listLRFFC = (ListView) findViewById(R.id.list_menu2);
		listLRFFC.setAdapter(new ListaLRFFCAdapter(this, nombres, img));

		listLRFFC.setOnItemClickListener(new AdapterView.OnItemClickListener() {
			@Override
			public void onItemClick(AdapterView<?> pariente, View view, int posicion, long id) {
				String nombre = (String) pariente.getItemAtPosition(posicion);
				Log.i("nombre: ", nombre);
				Intent intent = new Intent(ListaLRFFCActivity.this, ElementoLRFFCActivity.class);
				intent.putExtra("Nombre", nombre);
				intent.putExtra("Path", imgf[posicion].getAbsolutePath());
				intent.putExtra("Titulo", "Editar elemento LRFFC");
				startActivity(intent);
			}
		});

		add.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View view) {
				Intent intent = new Intent(ListaLRFFCActivity.this, ElementoLRFFCActivity.class);
				intent.putExtra("Titulo", "Agregar elemento LRFFC");
				startActivity(intent);
			}
		});

	}

}

package com.albertd.feel_learn;

//import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageView;

/**
 * Created by AlbertD on 11/11/2017.
 */

public class MenuLRFFCActivity extends FeelLearn{

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.menulrffc_screen);

		preferencias = getSharedPreferences(PREFERENCIAS, MODE_PRIVATE);
		ImageView nivel1, nivel2, nivel3;

		nivel1 = (ImageView) findViewById(R.id.LRFFCN1);
		nivel2 = (ImageView) findViewById(R.id.LRFFCN2);
		nivel3 = (ImageView) findViewById(R.id.LRFFCN3);

		nivel1.setOnClickListener(nivel1Listener);
		nivel2.setOnClickListener(nivel2Listener);
		nivel3.setOnClickListener(nivel3Listener);
	}

	private OnClickListener nivel1Listener = new View.OnClickListener(){
		public void onClick(View v){
			preferencias.edit().putInt(NIVEL, 1).commit();
			iniciarSeleccionLRFFC();
		}
	};

	private OnClickListener nivel2Listener = new View.OnClickListener(){
		public void onClick(View v){
			preferencias.edit().putInt(NIVEL, 2).commit();
			iniciarSeleccionLRFFC();
		}
	};

	private OnClickListener nivel3Listener = new View.OnClickListener(){
		public void onClick(View v){
			preferencias.edit().putInt(NIVEL, 3).commit();
			iniciarSeleccionLRFFC();
		}
	};

	public void iniciarSeleccionLRFFC(){
		Intent intento = new Intent(MenuLRFFCActivity.this, LRFFCSeleccionActivity.class);
		startActivity(intento);
	}
}

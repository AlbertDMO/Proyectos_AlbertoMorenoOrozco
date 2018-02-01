package com.albertd.feel_learn;

/**
 * Created by AlbertD on 10/11/2017.
 */
import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.app.AlertDialog;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageView;

public class MenuPrincipalActivity extends FeelLearn {

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.menuprincipal_screen);

		ImageView engrane, lrffc, emocion;

		engrane = (ImageView) findViewById(R.id.confEngrane);
		lrffc = (ImageView) findViewById(R.id.LRFFCMenu);
		emocion = (ImageView) findViewById(R.id.emocionMenu);

		//preferencias = getSharedPreferences(PREFERENCIAS, MODE_PRIVATE);

		engrane.setOnClickListener(engraneListener);
		lrffc.setOnClickListener(lrffcListener);
		emocion.setOnClickListener(emocionListener);
	}

	private OnClickListener engraneListener = new OnClickListener(){
		public void onClick(View v){
			Intent intento = new Intent(MenuPrincipalActivity.this, ConfiguracionActivity.class);
			startActivity(intento);
		}
	};

	private OnClickListener lrffcListener = new OnClickListener(){
		public void onClick(View v){
			Intent intento = new Intent(MenuPrincipalActivity.this, MenuLRFFCActivity.class);
			startActivity(intento);
		}
	};

	private OnClickListener emocionListener = new OnClickListener(){
		public void onClick(View v){
			Intent intento = new Intent(MenuPrincipalActivity.this, MenuEmocionActivity.class);
			startActivity(intento);
		}
	};

	@Override
	public void onDestroy(){
		super.onDestroy();
	}

	@Override
	public void onBackPressed() {
		final AlertDialog.Builder dialogo = new AlertDialog.Builder(this);
		dialogo.setCancelable(false);
		dialogo.setTitle("¿Seguro desea salir?");
		dialogo.setPositiveButton("Aceptar", new DialogInterface.OnClickListener(){
			public void onClick(DialogInterface dialog, int i){
				MenuPrincipalActivity.super.onBackPressed();
				//finish();
			}
		});
		dialogo.setNegativeButton("Cancelar", new DialogInterface.OnClickListener(){
			public void onClick(DialogInterface dialog, int i){
				dialog.cancel();
			}
		});
		dialogo.show();
	}
}

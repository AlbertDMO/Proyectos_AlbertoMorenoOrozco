package com.albertd.feel_learn;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

/**
 * Created by AlbertD on 16/11/2017.
 */

public class LoginActivity extends FeelLearn {

	EditText userEdit, pinEdit;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.login_screen);
		//getSupportActionBar().setDisplayHomeAsUpEnabled(true);

		Button logButton = (Button) findViewById(R.id.logButton);
		Button regButton = (Button) findViewById(R.id.regButton2);
		userEdit = (EditText) findViewById(R.id.logNombre);
		pinEdit = (EditText) findViewById(R.id.logPIN);

		logButton.setOnClickListener(btnListener);
		regButton.setOnClickListener(regListener);

		preferencias = getSharedPreferences(PREFERENCIAS, MODE_PRIVATE);
		dbh = DataBaseHelper.getInstance(getApplicationContext());
	}

	private OnClickListener btnListener = new OnClickListener(){
		public void onClick(View v){
			String strUser = userEdit.getText().toString();
			String strPin = pinEdit.getText().toString();

			if (strUser.length() == 0){
				userEdit.setError("El campo no puede ir vacío");
			}else if (strPin.length() == 0){
				pinEdit.setError("El campo no puede ir vacío");
			}else {
				SQLiteDatabase db = dbh.getReadableDatabase();
				Cursor c = db.rawQuery("Select PIN from NinoTEA WHERE NomUsuario LIKE ?", new String[]{strUser});
				//db.raw
				int pin = Integer.parseInt(strPin);
				if (c.moveToFirst()) {//El usuario existe
					//String strUserdb;
					int pindb;

					//strUserdb = c.getString(0);
					pindb = c.getInt(0);
					c.close();

					/*if(!strUser.equals(strUserdb)){
						//Toast.makeText(getApplicationContext(), "El usuario no existe", Toast.LENGTH_SHORT).show();
						userEdit.setError("Usuario incorrecto o no existe");
					}else if (pin != pindb){*/
					if (pin != pindb){
						//Toast.makeText(getApplicationContext(), "El PIN es incorrecto", Toast.LENGTH_SHORT).show();
						pinEdit.setError("El PIN es incorrecto");
						db.close();
					}else {
						preferencias.edit().putString(USUARIO_ACTUAL, strUser).commit();
						Intent intento = new Intent(LoginActivity.this, MenuPrincipalActivity.class).addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP | Intent.FLAG_ACTIVITY_CLEAR_TOP);
						startActivity(intento);
						db.close();
						finish();
					}
				}else {
					userEdit.setError("Usuario incorrecto o no existe");
					c.close();
					db.close();
					//Log.i("actual", preferencias.getString(USUARIO_ACTUAL, ""));
				}
			}
		}
	};

	private OnClickListener regListener = new OnClickListener() {
		@Override
		public void onClick(View view) {
			Intent intento = new Intent(LoginActivity.this, RegistroUsuarioActivity.class);
			startActivity(intento);
			//finish();
		}
	};

	@Override
	public void onBackPressed() {
	}
}

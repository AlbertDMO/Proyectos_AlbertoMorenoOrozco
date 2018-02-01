package com.albertd.feel_learn;


import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

/**
 * Created by AlbertD on 10/11/2017.
 */

public class RegistroUsuarioActivity extends FeelLearn {

	private String nombre, user;
	private int pin, pin2;
	private EditText regNombre, regUser, regPIN, regPIN2;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.regusuario_screen);

		regNombre = (EditText) findViewById(R.id.regNombre);
		regUser = (EditText) findViewById(R.id.regUser);
		regPIN = (EditText) findViewById(R.id.regPIN);
		regPIN2 = (EditText) findViewById(R.id.regPIN2);

		Button btn = (Button) findViewById(R.id.regButton);
		btn.setOnClickListener(btnListener);
		dbh = DataBaseHelper.getInstance(getApplicationContext());
		preferencias = getSharedPreferences(PREFERENCIAS, MODE_PRIVATE);
	}

	private OnClickListener btnListener = new OnClickListener() {
		@Override
		public void onClick(View view) {
			nombre = regNombre.getText().toString();
			user = regUser.getText().toString().toLowerCase();
			String strpin = regPIN.getText().toString().trim();
			String strpin2 = regPIN2.getText().toString().trim();
			//pin = Integer.parseInt(regPIN.getText().toString());
			if (user.length() == 0){
				regUser.setError("El campo no puede ir vacío");
			}else if (strpin.length() == 0){
				regPIN.setError("El campo no puede ir vacío");
			}else if (strpin2.length() == 0){
				regPIN2.setError("El campo no puede ir vacío");
			}else {
				pin = Integer.parseInt(strpin);
				pin2 = Integer.parseInt(strpin2);

				if (pin != pin2){
					Toast.makeText(RegistroUsuarioActivity.this, "Los PIN no coinciden", Toast.LENGTH_SHORT).show();
				}else {
					dbh.addNino(nombre, user, pin);
					preferencias.edit().putString(USUARIO_ACTUAL, user).commit();
					//Log.e("msg", preferencias.getString("Usuario_actual", null));
					Intent intent = new Intent(RegistroUsuarioActivity.this, MenuPrincipalActivity.class).setFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP | Intent.FLAG_ACTIVITY_CLEAR_TOP);
					startActivity(intent);
					finish();
				}
			}
		}
	};
}
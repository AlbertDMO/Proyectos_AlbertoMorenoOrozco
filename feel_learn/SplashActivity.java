package com.albertd.feel_learn;

/**
 * Created by AlbertD on 10/11/2017.
 */
import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.widget.ProgressBar;

public class SplashActivity extends FeelLearn {

	private ProgressBar mProgreso;
	private Intent intent;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.splash_screen);
		mProgreso = (ProgressBar) findViewById(R.id.Splash_Screen_progressBar);
		preferencias = getSharedPreferences(PREFERENCIAS, MODE_PRIVATE);
		dbh = DataBaseHelper.getInstance(getApplicationContext());

		//ver registrados
		SQLiteDatabase db = dbh.getReadableDatabase();
		Cursor c = db.rawQuery("Select NomUsuario,PIN from NinoTEA", null);

		if (c.moveToFirst()){
			do {
				Log.i("user:", c.getString(0));
				Log.i("pin:", c.getInt(1)+"");
			}while (c.moveToNext());
		}

		// Start lengthy operation in a background thread
		new Thread(new Runnable() {
			public void run() {
				for (int progreso=0; progreso<100; progreso+=10) {
					try {
						Thread.sleep(100);
						mProgreso.setProgress(progreso);
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
				if (preferencias.getBoolean("my_first_time", true) || dbh.getCountNinos() == 0) {
					//Si es la primera vez que se usa la app o no tiene ninos registrados
					//first time task
					intent = new Intent(SplashActivity.this, RegistroUsuarioActivity.class);
					// record the fact that the app has been started at least once
					preferencias.edit().putBoolean("my_first_time", false).commit();
				}else {
					intent = new Intent(SplashActivity.this, LoginActivity.class);
					//intent = new Intent(SplashActivity.this, MenuPrincipalActivity.class);
				}
				startActivity(intent);
				finish();
			}
		}).start();
	}

}

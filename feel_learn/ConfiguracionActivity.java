package com.albertd.feel_learn;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AlertDialog;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

/**
 * Created by AlbertD on 10/11/2017.
 */

public class ConfiguracionActivity extends FeelLearn{

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.config_screen);
		getSupportActionBar().setDisplayHomeAsUpEnabled(true);

		preferencias = getSharedPreferences(PREFERENCIAS, MODE_PRIVATE);
		dbh = DataBaseHelper.getInstance(getApplicationContext());

		ListView listMenu = (ListView) findViewById(R.id.list_menu1);

		final String[] opciones = {
				"Configuración de módulo LRFFC",
				"Registrar nuevo usuario",
				"Cambiar de usuario",
				"Eliminar usuario",
				"Resultados y estadísticas",
				"Ayuda",
				"Acerca de FEEL&LEARN"
		};

		ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, R.layout.config_item, opciones);
		listMenu.setAdapter(adapter);

		listMenu.setOnItemClickListener(new OnItemClickListener(){
			public void onItemClick(AdapterView<?> parent, View itemClicked, int position, long id){
				TextView textView = (TextView) itemClicked;
				String strText = textView.getText().toString();

				if (strText.equalsIgnoreCase(opciones[0])){
					Intent intent = new Intent(ConfiguracionActivity.this, ConfiguracionLRFFCActivity.class);
					startActivity(intent);
				}else if (strText.equalsIgnoreCase(opciones[1])){
					Intent intent = new Intent(ConfiguracionActivity.this, RegistroUsuarioActivity.class);
					startActivity(intent);
					//finish();
				}else if (strText.equalsIgnoreCase(opciones[2])){
					Intent intent = new Intent(ConfiguracionActivity.this, LoginActivity.class);
					startActivity(intent);
				}else if (strText.equalsIgnoreCase(opciones[3])){
					//Log.i("mensaje","Seleccionó 4");
					final AlertDialog.Builder dialogo = new AlertDialog.Builder(ConfiguracionActivity.this);
					dialogo.setCancelable(false);
					dialogo.setTitle("¿Desea borrar el usuario actual?");
					dialogo.setMessage("Ésto borrará todo el contenido del usuario");
					dialogo.setPositiveButton("Aceptar", new DialogInterface.OnClickListener(){
						public void onClick(DialogInterface dialog, int i){
							Log.i("ninos: ", dbh.getCountNinos()+"");
							dbh.deleteNino(preferencias.getString(USUARIO_ACTUAL, ""));
							preferencias.edit().putString(USUARIO_ACTUAL, "").commit();
							Log.i("ninos: ", dbh.getCountNinos()+"");
							Intent intent = new Intent(ConfiguracionActivity.this, LoginActivity.class);
							startActivity(intent);
							//finish();
						}
					});
					dialogo.setNegativeButton("Cancelar", new DialogInterface.OnClickListener(){
						public void onClick(DialogInterface dialog, int i){
							dialog.cancel();
						}
					});
					dialogo.show();
				}else if (strText.equalsIgnoreCase(opciones[4])){
					Intent intent = new Intent(ConfiguracionActivity.this, EstadisticasActivity.class);
					startActivity(intent);
				}else if (strText.equalsIgnoreCase(opciones[5])) {
					Log.i("mensaje","Seleccionó 6");
				}else if (strText.equalsIgnoreCase(opciones[6])){
					Log.i("mensaje","Seleccionó 7");
				}

				//finish();
			}
		});
	}
}

package com.albertd.feel_learn;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

/**
 * Created by AlbertD on 16/11/2017.
 */

public class ConfiguracionLRFFCActivity extends FeelLearn {

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.config_screen);
		getSupportActionBar().setDisplayHomeAsUpEnabled(true);

		ListView listMenu = (ListView) findViewById(R.id.list_menu1);
		preferencias = getSharedPreferences(PREFERENCIAS, MODE_PRIVATE);

		final String[] opciones = {
				"Nivel 1",
				"Nivel 2",
				"Nivel 3"
		};

		ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, R.layout.config_item, opciones);
		listMenu.setAdapter(adapter);

		listMenu.setOnItemClickListener(new AdapterView.OnItemClickListener(){
			public void onItemClick(AdapterView<?> parent, View itemClicked, int position, long id){
				TextView textView = (TextView) itemClicked;
				String strText = textView.getText().toString();

				if (strText.equalsIgnoreCase(opciones[0])){
					//Log.i("mensaje", "Seleccionó 1");
					preferencias.edit().putInt(NIVEL, 1).commit();
				}else if (strText.equalsIgnoreCase(opciones[1])){
					//Log.i("mensaje", "Seleccionó 2");
					preferencias.edit().putInt(NIVEL, 2).commit();
				}else if (strText.equalsIgnoreCase(opciones[2])) {
					//Log.i("mensaje", "Seleccionó 3");
					preferencias.edit().putInt(NIVEL, 3).commit();
				}
				Intent intent = new Intent(ConfiguracionLRFFCActivity.this, ListaLRFFCActivity.class);
				startActivity(intent);
			}
		});
	}
}

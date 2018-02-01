package com.albertd.feel_learn;

import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;

/**
 * Created by AlbertD on 04/12/2017.
 */

public class FeelLearn extends AppCompatActivity {

	final String PREFERENCIAS = "Preferencias";
	final String USUARIO_ACTUAL = "Usuario_actual";
	final String NIVEL = "Nivel";

	SharedPreferences preferencias;
	DataBaseHelper dbh;
}

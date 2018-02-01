package com.albertd.feel_learn;

import android.database.Cursor;
import android.os.Bundle;
import android.support.v4.app.ListFragment;
import android.support.v4.widget.SimpleCursorAdapter;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;

/**
 * Created by AlbertD on 21/11/2017.
 */

public class EstadisticasFragment extends ListFragment {

	private final String[] opciones = {
			"Intentos: ",
			"Aciertos: ",
			"Errores: ",
			"Tiempo Total: ",
			"Tiempo medio por ejercicio: "
	};

	public EstadisticasFragment(){
	}

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		ArrayAdapter<String> adapter1 = new ArrayAdapter<String>(getActivity(), android.R.layout.simple_list_item_1, opciones);

		setListAdapter(adapter1);

		/*Cursor mCursor = new Cursor();
		ListAdapter adapter = new SimpleCursorAdapter(
				getActivity(),
				android.R.layout.simple_list_item_2,
				mCursor,
				new String[] {"Intentos", "20"},
				new int[] {android.R.id.text1, android.R.id.text2});*/
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
		// Inflate the layout for this fragment
		return inflater.inflate(R.layout.estadisticas_fragment, container, false);
	}
}

package com.albertd.feel_learn;

import java.io.File;
import java.util.ArrayList;

import android.content.Context;
import android.graphics.Bitmap;
import android.net.Uri;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;


/**
 * Created by AlbertD on 30/11/2017.
 */

public class ListaLRFFCAdapter extends BaseAdapter {

	private Context contexto;
	//private ArrayList<HashMap<String,String>> entrada;
	private String[] nombres;
	private ArrayList<Bitmap> uris;
	private static LayoutInflater inflater = null;

	public ListaLRFFCAdapter(Context context, String[] nombres, ArrayList<Bitmap> uris) {
		contexto = context;
		this.nombres = nombres;
		this.uris = uris;
		inflater = (LayoutInflater) contexto.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
	}

	@Override
	public int getCount() {
		return nombres.length;
	}

	@Override
	public Object getItem(int posicion) {
		return nombres[posicion];
	}

	@Override
	public long getItemId(int posicion) {
		return posicion;
	}

	public class Holder
	{
		TextView lrffcText;
		ImageView lrffcImg;
	}

	@Override
	public View getView(int posicion, View view, ViewGroup pariente) {

		Holder holder = new Holder();

		View vi = view;
		if(view == null) vi = inflater.inflate(R.layout.listalrffc_item, null);

		holder.lrffcText = (TextView) vi.findViewById(R.id.LRFFC_Nombre);
		holder.lrffcImg = (ImageView) vi.findViewById(R.id.LRFFC_Img);

		holder.lrffcText.setText(nombres[posicion]);
		//holder.lrffcImg.setImageURI(Uri.parse(uris[posicion]));
		//holder.lrffcImg.setImageURI(Uri.fromFile(uris[posicion]));
		holder.lrffcImg.setImageBitmap(uris.get(posicion));

		//HashMap<String, String> elto = new HashMap<String, String>();
		//elto = entrada.get(posicion);

		//lrffcText.setText(elto.get());

		return vi;
	}
}

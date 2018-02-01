package com.albertd.feel_learn;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.*;

/**
 * Created by AlbertD on 22/11/2017.
 */

public class DataBaseHelper extends SQLiteOpenHelper {

	// All Static variables
	private static DataBaseHelper sInstance;
	// Database Version
	private static final int DATABASE_VERSION = 1;

	// Database Name
	private static final String DATABASE_NAME = "FeelLearn.DB";

	//Table names
	private static final String NINO_TEA = "NinoTEA";
	private static final String ELEMENTO_LRFFC = "ElementoLRFFC";
	private static final String INTENTO_LRFFC = "IntentoLRFFC";
	private static final String INTENTO_EMOCION = "IntentoEmocion";

	//Column names
	private static final String NOM_USUARIO = "NomUsuario";
	private static final String NOMBRE = "Nombre";
	private static final String PIN = "PIN";

	private static final String CAR1 = "Caracteristica1";
	private static final String CAR2 = "Caracteristica2";
	private static final String URI = "URI_Imagen";
	private static final String NIVEL = "Nivel";

	//Strings para crear tablas
	private static final String CREA_NINOTEA = "CREATE TABLE NinoTEA(" +
			NOM_USUARIO + " TEXT PRIMARY KEY, " +
			NOMBRE + " TEXT," +
			PIN + " INTEGER NOT NULL" +
			")";

	private static final String CREA_ELEMENTO_LRFFC = "CREATE TABLE ElementoLRFFC(" +
			NOMBRE + " TEXT PRIMARY KEY," +
			CAR1 + " TEXT NOT NULL," +
			CAR2 + " TEXT NOT NULL," +
			URI + " TEXT NOT NULL," +
			NIVEL + " INTEGER NOT NULL," +
			NOM_USUARIO + " TEXT NOT NULL," +
			"FOREIGN KEY(" + NOM_USUARIO + ") REFERENCES " + NINO_TEA + "(" + NOM_USUARIO + ")" +
			")";

	private static final String CREA_INTENTO_LRFFC = "CREATE TABLE IntentoLRFFC(" +
			"ID_Intento INTEGER PRIMARY KEY AUTOINCREMENT," +
			"Fecha_Hora DATETIME NOT NULL," +
			"Tiempo INTEGER NOT NULL," +
			"Acierto_Falla INTEGER NOT NULL," +
			"Nivel INTEGER NOT NULL," +
			NOM_USUARIO + " TEXT NOT NULL," +
			"FOREIGN KEY(" + NOM_USUARIO + ") REFERENCES " + NINO_TEA + "(" + NOM_USUARIO + ")" +
			")";
	private static final String CREA_INTENTO_EMOCION = "CREATE TABLE IntentoEmocion(" +
			"ID_Intento INTEGER PRIMARY KEY AUTOINCREMENT," +
			"Fecha_Hora DATETIME NOT NULL," +
			"Tiempo INTEGER NOT NULL," +
			"Acierto_Falla INTEGER NOT NULL," +
			"NomUsuario TEXT NOT NULL," +
			"FOREIGN KEY(" + NOM_USUARIO + ") REFERENCES " + NINO_TEA + "(" + NOM_USUARIO + ")" +
			")";


	public static synchronized DataBaseHelper getInstance(Context context){
		// Use the application context, which will ensure that you
		// don't accidentally leak an Activity's context.
		// See this article for more information: http://bit.ly/6LRzfx
		if (sInstance == null) {
			sInstance = new DataBaseHelper(context.getApplicationContext());
		}
		return sInstance;
	}

	public DataBaseHelper(Context context) {
		super(context, DATABASE_NAME, null, DATABASE_VERSION);
	}

	@Override
	public void onCreate(SQLiteDatabase db){
		db.execSQL(CREA_NINOTEA);
		db.execSQL(CREA_ELEMENTO_LRFFC);
		db.execSQL(CREA_INTENTO_LRFFC);
		db.execSQL(CREA_INTENTO_EMOCION);
	}

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
		db.execSQL("DROP TABLE IF EXISTS " + NINO_TEA);
		db.execSQL("DROP TABLE IF EXISTS " + ELEMENTO_LRFFC);
		db.execSQL("DROP TABLE IF EXISTS " + INTENTO_LRFFC);
		db.execSQL("DROP TABLE IF EXISTS " + INTENTO_EMOCION);

		onCreate(db);
	}

	@Override
	public void onConfigure(SQLiteDatabase db) {
		super.onConfigure(db);
		if (!db.isReadOnly()) {
			// Enable foreign key constraints
			db.execSQL("PRAGMA foreign_keys=ON;");
		}
	}

	//CRUD Operations

	public void addNino(String nombre, String nomUsuario, int pin){
		SQLiteDatabase db = this.getWritableDatabase();

		ContentValues cv = new ContentValues();
		cv.put(NOM_USUARIO, nomUsuario);
		cv.put(NOMBRE, nombre);
		cv.put(PIN, pin);

		db.insert(NINO_TEA, null, cv);
		db.close();
	}

	public void deleteNino(String user){
		SQLiteDatabase db = this.getWritableDatabase();
		db.delete(NINO_TEA, "NomUsuario LIKE ?", new String[] {user});
		db.close();
	}

	public int getCountNinos(){
		SQLiteDatabase db = this.getReadableDatabase();
		Cursor c = db.rawQuery("Select * from " + NINO_TEA, null);
		int count = c.getCount();
		c.close();
		db.close();
		return count;
	}

	public void addElementoLRFFC(String nombre, String car1, String car2, String uri, int nivel, String nomUsuario){
		SQLiteDatabase db = this.getWritableDatabase();
		ContentValues cv = new ContentValues();
		cv.put(NOMBRE, nombre);
		cv.put(CAR1, car1);
		cv.put(CAR2, car2);
		cv.put(URI, uri);

		cv.put(NIVEL, nivel);
		cv.put(NOM_USUARIO, nomUsuario);

		db.insert(ELEMENTO_LRFFC, null, cv);
		db.close();
	}

	public void deleteElementoLRFFC(String nombre){
		SQLiteDatabase db = this.getWritableDatabase();
		db.delete(ELEMENTO_LRFFC, NOMBRE + " LIKE ?", new String[] {nombre});
		db.close();
	}

}

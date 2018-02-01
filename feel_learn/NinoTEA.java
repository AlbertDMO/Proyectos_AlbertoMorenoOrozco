package com.albertd.feel_learn;

/**
 * Created by AlbertD on 22/11/2017.
 */

public class NinoTEA {

	private String nomUsuario, nombre;
	private int pin;

	//Constructores
	public NinoTEA(){
	}

	public NinoTEA(String nomUsuario, String nombre, int pin){
		this.nomUsuario = nomUsuario;
		this.nombre = nombre;
		this.pin = pin;
	}

	public NinoTEA(String nomUsuario, int pin){
		this.nomUsuario = nomUsuario;
		this.pin = pin;
	}

	//Getters
	public String getNomUsuario(){
		return this.nomUsuario;
	}

	public String getNombre(){
		return this.nombre;
	}

	public int getPin(){
		return this.pin;
	}

	//Setters
	public void setNomUsuario(String nomUsuario){
		this.nomUsuario = nomUsuario;
	}

	public void setNombre(String nombre){
		this.nombre = nombre;
	}

	public void setPin(int pin){
		this.pin = pin;
	}

}

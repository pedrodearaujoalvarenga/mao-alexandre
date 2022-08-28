package com.cefetmg.braomecnico;

import java.util.List;

import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.GET;
import retrofit2.http.POST;

public interface JsonPlaceHolderApi {

    @GET("HANGLOOSE")
    Call<List<Post>> callHangloose();

    @GET("SPIDERMAN")
    Call<List<Post>> callSpiderman();

    @GET("POINTER")
    Call<List<Post>> callPointer();

    @GET("GUN")
    Call<List<Post>> callGun();

}
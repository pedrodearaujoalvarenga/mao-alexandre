package com.cefetmg.braomecnico;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;


public class MainActivity extends AppCompatActivity {

    TextView mainText;
    Button buttonSkipWifi;

    Button hangloose, pointer, gun, spiderman;
    Boolean canSend = true;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout);
        buttonSkipWifi = findViewById(R.id.button);
        buttonSkipWifi.setOnClickListener(
                v->{
                    setContentView(R.layout.activity_main);
                    mainText = findViewById(R.id.textView3);

                    Handler handler = new Handler();
                    handler.postDelayed(() -> {

                        mainText.setVisibility(View.GONE);
                    }, 5000);

                    hangloose = findViewById(R.id.hangloose);
                    spiderman = findViewById(R.id.spiderman);
                    gun = findViewById(R.id.gun);
                    pointer = findViewById(R.id.pointer);

                    hangloose.setOnClickListener(
                            a->{
                                if(canSend){
                                sendHangloose();}
                            }
                    );

                    spiderman.setOnClickListener(
                            b->{
                                if(canSend) {
                                    sendSpider();
                                }
                            }
                    );

                    gun.setOnClickListener(
                            c->{
                                if(canSend){
                                sendGun();
                                }
                            }
                    );

                    pointer.setOnClickListener(
                            d->{
                                if(canSend){
                                sendPointer();
                                }
                            }
                    );






                }
        );
    }

    void sendSpider(){
        Toast.makeText(getApplicationContext(),"Enviando: homem-aranha", Toast.LENGTH_SHORT).show();

        canSend = false;
        String address = "http://192.168.4.1/";
        Retrofit retrofit = new Retrofit.Builder().baseUrl(address).addConverterFactory(GsonConverterFactory.create()).build();
        JsonPlaceHolderApi jsonPlaceHolderApi = retrofit.create(JsonPlaceHolderApi.class);
        Call<List<Post>> call = jsonPlaceHolderApi.callSpiderman();
        call.enqueue(new Callback<List<Post>>() {
            @Override
            public void onResponse(Call<List<Post>> call, Response<List<Post>> response) {
                canSend = true;
            }

            @Override
            public void onFailure(Call<List<Post>> call, Throwable t) {
                canSend = true;
            }
        });

    }

    void sendGun(){
        Toast.makeText(getApplicationContext(),"Enviando: arma", Toast.LENGTH_SHORT).show();

        canSend = false;
        String address = "http://192.168.4.1/";
        Retrofit retrofit = new Retrofit.Builder().baseUrl(address).addConverterFactory(GsonConverterFactory.create()).build();
        JsonPlaceHolderApi jsonPlaceHolderApi = retrofit.create(JsonPlaceHolderApi.class);
        Call<List<Post>> call = jsonPlaceHolderApi.callGun();
        call.enqueue(new Callback<List<Post>>() {
            @Override
            public void onResponse(Call<List<Post>> call, Response<List<Post>> response) {
                canSend = true;
            }

            @Override
            public void onFailure(Call<List<Post>> call, Throwable t) {
                canSend = true;
            }
        });

    }

    void sendPointer(){

        Toast.makeText(getApplicationContext(),"Enviando: apontar o dedo", Toast.LENGTH_SHORT).show();

        canSend = false;
        String address = "http://192.168.4.1/";
        Retrofit retrofit = new Retrofit.Builder().baseUrl(address).addConverterFactory(GsonConverterFactory.create()).build();
        JsonPlaceHolderApi jsonPlaceHolderApi = retrofit.create(JsonPlaceHolderApi.class);
        Call<List<Post>> call = jsonPlaceHolderApi.callPointer();
        call.enqueue(new Callback<List<Post>>() {
            @Override
            public void onResponse(Call<List<Post>> call, Response<List<Post>> response) {
                canSend = true;
            }

            @Override
            public void onFailure(Call<List<Post>> call, Throwable t) {

                canSend = true;
            }
        });
    }
    void sendHangloose(){

        Toast.makeText(getApplicationContext(),"Enviando: Hang-loose", Toast.LENGTH_SHORT).show();

        canSend = false;
        String address = "http://192.168.4.1/";
        Retrofit retrofit = new Retrofit.Builder().baseUrl(address).addConverterFactory(GsonConverterFactory.create()).build();
        JsonPlaceHolderApi jsonPlaceHolderApi = retrofit.create(JsonPlaceHolderApi.class);
        Call<List<Post>> call = jsonPlaceHolderApi.callHangloose();
        call.enqueue(new Callback<List<Post>>() {
            @Override
            public void onResponse(Call<List<Post>> call, Response<List<Post>> response) {
                canSend = true;
            }

            @Override
            public void onFailure(Call<List<Post>> call, Throwable t) {
                canSend = true;
            }
        });
    }




}
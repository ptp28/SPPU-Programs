package com.example.lenovo.video;

import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ProgressBar;
import android.widget.VideoView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

ImageButton button,stop,pause,forw,back;
VideoView videoView;

int flag = 0, temp, end, pb;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button = (ImageButton) findViewById(R.id.button);
        button.setOnClickListener(this);
        stop =(ImageButton) findViewById(R.id.stop);
        stop.setOnClickListener(this);
        pause = (ImageButton) findViewById(R.id.pause);
        pause.setOnClickListener(this);
        forw = (ImageButton) findViewById(R.id.forward);
        forw.setOnClickListener(this);
        back = (ImageButton) findViewById(R.id.back);
        back.setOnClickListener(this);


        videoView = (VideoView) findViewById(R.id.videoView);

        String path = "android.resource://com.example.lenovo.video/"+R.raw.kold;
        Uri uri = Uri.parse(path); //Uniform Resource Identifier = Identifying a resource file
        videoView.setVideoURI(uri);
        end = videoView.getDuration();


    }

    public void onClick(View v)
    {

        switch(v.getId())
        {
            case R.id.button:
                videoView.start();
                    break;
            case R.id.stop:
                pb = videoView.getCurrentPosition();
                int so = end-pb;

                videoView.stopPlayback();
                videoView.seekTo(so);
                finish();
                break;
            case R.id.pause:
                flag++;


                if(flag%2==0)
                {
                    //videoView.seekTo(temp+100);
                    videoView.start();


                }
                else
                {
                    videoView.pause();
                    temp = videoView.getCurrentPosition();
                }
                break;
            case R.id.forward:
                int temp1 = videoView.getCurrentPosition();
                videoView.seekTo(temp1+5000);
                break;
            case R.id.back:
                int temp2 = videoView.getCurrentPosition();
                videoView.seekTo(temp2-5000);
                break;
        }

    }
}

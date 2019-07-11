package com.example.lenovo.database;


import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    Database d;
    EditText name,number;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        d=new Database(this);
        name=(EditText)findViewById(R.id.name);
        number=(EditText)findViewById(R.id.number);
    }

    public void search(View view) {
        String namecon;
        namecon = "";
        namecon = name.getText().toString();
        d.open();
        String no = d.search(namecon);
        d.close();
        if (!no.equals("-1")) {
            number.setText(no);
            Toast.makeText(this, "Number FOUND.", Toast.LENGTH_SHORT).show();
        } else {
            number.setText("");
            Toast.makeText(this, "RECORD DOES NOT EXIST", Toast.LENGTH_SHORT).show();
        }
    }

    public void register(View view) {
        String namecon,numbercon,id;
        namecon=name.getText().toString();
        numbercon=number.getText().toString();
        if(namecon.length()<10)
        {
            Toast.makeText(this, "ENTER VALID NUMBER ", Toast.LENGTH_SHORT).show();
            number.setText("");
        }

        name.setText("");
        number.setText("");
        if(!namecon.equals("")){
            if(numbercon.length()==10) {
                id = namecon.substring(2) + numbercon.substring(7);
                d.open();
                long s=d.createInsert(id, namecon, numbercon);
                d.close();
                if(s == -1)
                    Toast.makeText(this, "NUMBER EXISTS ", Toast.LENGTH_SHORT).show();
                else
                    Toast.makeText(this, "CONTACT ADDED TO DATABASE", Toast.LENGTH_SHORT).show();
            }
            else{
                Toast.makeText(this, "Enter a valid number.", Toast.LENGTH_SHORT).show();
            }
        }
        else{
            Toast.makeText(this, "Name cant be empty.", Toast.LENGTH_SHORT).show();
        }
    }
}


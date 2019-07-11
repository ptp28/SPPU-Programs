package com.example.lenovo.database;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class Database {
    public static final String KEY_CONID = "conid";
    public static final String NAME = "name";
    public static final String NUMBER = "number";

    private static final String DATABASE_NAME = "Contacts";
    private static final String DATABASE_LIST = "contact";
    private static final int DATABASE_VERSION = 1;

    private DbHelper ourHelper;
    private final Context ourContext;
    private SQLiteDatabase ourDatabase;

    private static class DbHelper extends SQLiteOpenHelper {

        public DbHelper(Context context) {
            super(context, DATABASE_NAME, null, DATABASE_VERSION);
            // TODO Auto-generated constructor stub
        }

        @Override
        public void onCreate(SQLiteDatabase db) {
            // TODO Auto-generated method stub
            db.execSQL(" CREATE TABLE " + DATABASE_LIST + " (" +
                    KEY_CONID + " TEXT PRIMARY KEY, " +
                    NAME + " TEXT NOT NULL, " +
                    NUMBER + " TEXT NOT NULL);"
            );
        }

        @Override
        public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
            // TODO Auto-generated method stub

            db.execSQL("DROP TABLE IF EXISTS " + DATABASE_LIST);
            onCreate(db);
        }

    }
    public Database(Context c){
        ourContext = c;
    }
    public Database open()throws SQLException {
        ourHelper = new DbHelper(ourContext);
        ourDatabase = ourHelper.getWritableDatabase();
        return this;
    }
    public void close(){
        ourHelper.close();
    }
    public long createInsert(String conid, String name, String number) {
        // TODO Auto-generated method stub
        ContentValues cv = new ContentValues();
        cv.put(KEY_CONID, conid);
        cv.put(NAME, name);
        cv.put(NUMBER, number);
        return ourDatabase.insert(DATABASE_LIST, null, cv);

    }

    public String search(String name){
        String number="";

        String sql = "SELECT * FROM " + DATABASE_LIST + " WHERE " + NAME + " LIKE '%" + name + "%'";
        Cursor cursor = ourDatabase.rawQuery(sql, null);

        if(cursor.getCount() > 0){
            // means search has returned data

            if (cursor.moveToFirst()) {
                do {
                    number = cursor.getString(cursor.getColumnIndex(NUMBER));
                    // display your search result here in RecyclerView or in any manner
                } while (cursor.moveToNext());
            }

        } else {
            number = "-1";
        }
        cursor.close();
        return number;
    }
}

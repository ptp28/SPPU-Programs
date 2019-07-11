/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.pvg;

import javax.ejb.Stateless;

/**
 *
 * @author CompLab4
 */
@Stateless
public class EJBCalci implements EJBCalciLocal {

    // Add business logic below. (Right-click in editor and choose
    // "Insert Code > Add Business Method")
    @Override
    public int add(int number1,int number2)
    {
        return number1+number2;
    }
     @Override
    public int sub(int number1,int number2)
    {
        return number1-number2;
    }
     @Override
    public int mul(int number1,int number2)
    {
        return number1*number2;
    }
     @Override
    public int div(int number1,int number2)
    {
        return number1/number2;
    }
    
}

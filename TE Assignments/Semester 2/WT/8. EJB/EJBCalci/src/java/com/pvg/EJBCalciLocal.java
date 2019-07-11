/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.pvg;

import javax.ejb.Local;

/**
 *
 * @author CompLab4
 */
@Local
public interface EJBCalciLocal {
    int add(int number1,int number2);
    int sub(int number1,int number2);
    int mul(int number1,int number2);
    int div(int number1,int number2);
}

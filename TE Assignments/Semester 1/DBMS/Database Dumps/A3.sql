CREATE DATABASE  IF NOT EXISTS `db3` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `db3`;
-- MySQL dump 10.13  Distrib 5.7.17, for macos10.12 (x86_64)
--
-- Host: 127.0.0.1    Database: db3
-- ------------------------------------------------------
-- Server version	5.7.22

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `account` (
  `accNo` int(11) NOT NULL,
  `branchName` varchar(30) NOT NULL,
  `balance` int(11) DEFAULT NULL,
  PRIMARY KEY (`accNo`),
  KEY `branchName` (`branchName`),
  CONSTRAINT `account_ibfk_1` FOREIGN KEY (`branchName`) REFERENCES `branch` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES (123,'CAMP',4500),(129,'DECCAN',5),(345,'DOWNTOWN',4150),(567,'SWARGATE',400),(789,'DECCAN',45015),(901,'CAMP',45055);
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `borrower`
--

DROP TABLE IF EXISTS `borrower`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `borrower` (
  `loanNo` int(11) DEFAULT NULL,
  `customerName` varchar(30) DEFAULT NULL,
  KEY `loanNo` (`loanNo`),
  KEY `customerName` (`customerName`),
  CONSTRAINT `borrower_ibfk_1` FOREIGN KEY (`loanNo`) REFERENCES `loan` (`loanNo`),
  CONSTRAINT `borrower_ibfk_2` FOREIGN KEY (`customerName`) REFERENCES `customer` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `borrower`
--

LOCK TABLES `borrower` WRITE;
/*!40000 ALTER TABLE `borrower` DISABLE KEYS */;
INSERT INTO `borrower` VALUES (1,'C1'),(1,'C1'),(2,'C5'),(3,'C2'),(5,'C3');
/*!40000 ALTER TABLE `borrower` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `branch`
--

DROP TABLE IF EXISTS `branch`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `branch` (
  `name` varchar(30) NOT NULL,
  `city` text NOT NULL,
  `assets` int(11) DEFAULT NULL,
  PRIMARY KEY (`name`),
  UNIQUE KEY `assets` (`assets`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `branch`
--

LOCK TABLES `branch` WRITE;
/*!40000 ALTER TABLE `branch` DISABLE KEYS */;
INSERT INTO `branch` VALUES ('CAMP','PUNE',40000),('DECCAN','DELHI',400),('DOWNTOWN','NEW YORK',123456),('SWARGATE','MUMBAI',34000);
/*!40000 ALTER TABLE `branch` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer` (
  `name` varchar(30) NOT NULL,
  `address` text NOT NULL,
  `city` text NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES ('C1','GANGADHAM','PUNE'),('C2','BORIWALI','DELHI'),('C3','MG ROAD','MUMBAI'),('C4','5TH AVENUE','NEW YORK'),('C5','UPSTATE','NEW YORK'),('C6','CAMP','PUNE');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `depositor`
--

DROP TABLE IF EXISTS `depositor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `depositor` (
  `customerName` varchar(30) NOT NULL,
  `accountNo` int(11) DEFAULT NULL,
  KEY `customerName` (`customerName`),
  KEY `accountNo` (`accountNo`),
  CONSTRAINT `depositor_ibfk_1` FOREIGN KEY (`customerName`) REFERENCES `customer` (`name`),
  CONSTRAINT `depositor_ibfk_2` FOREIGN KEY (`accountNo`) REFERENCES `account` (`accNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `depositor`
--

LOCK TABLES `depositor` WRITE;
/*!40000 ALTER TABLE `depositor` DISABLE KEYS */;
INSERT INTO `depositor` VALUES ('C1',123),('C2',567),('C3',345),('C4',901),('C5',789),('C6',129);
/*!40000 ALTER TABLE `depositor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `loan`
--

DROP TABLE IF EXISTS `loan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `loan` (
  `loanNo` int(11) NOT NULL,
  `branchName` varchar(30) DEFAULT NULL,
  `amount` int(11) DEFAULT NULL,
  PRIMARY KEY (`loanNo`),
  KEY `branchName` (`branchName`),
  CONSTRAINT `loan_ibfk_1` FOREIGN KEY (`branchName`) REFERENCES `branch` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `loan`
--

LOCK TABLES `loan` WRITE;
/*!40000 ALTER TABLE `loan` DISABLE KEYS */;
INSERT INTO `loan` VALUES (1,'CAMP',1200),(2,'DOWNTOWN',1300),(3,'CAMP',1400),(5,'SWARGATE',1600);
/*!40000 ALTER TABLE `loan` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-10-27 17:01:07

-- create database db3;
-- use db3;
-- create table branch(name varchar(30) NOT NULL, city text NOT NULL, assets int unique , primary key(name));
-- create table customer(name varchar(30) not null , address text not null , city text not null , primary key(name));
-- create table loan(loanNo int , branchName varchar(30), amount int,primary key(loanNo) , foreign key(branchName) references db3.branch(name));
-- create table account(accNo int not null ,branchName varchar(30) not null, balance int , primary key(accNo) , foreign key(branchName) references branch(name));
-- create table depositor(customerName varchar(30) NOT NULL , accountNo int, foreign key(customerName) references customer(name) , foreign key(accountNo) references account(accNo));
-- create table borrower(loanNo int  , customerName varchar(30) , foreign key(loanNo) references db3.loan(loanNo) , foreign key(customerName) references db3.customer(name));
-- 
-- insert into branch values("CAMP","PUNE",40000);
-- insert into branch values("DOWNTOWN","NEW YORK",123456);
-- insert into branch values("SWARGATE","MUMBAI",34000);
-- insert into branch values("DECCAN","DELHI",400);
-- 
-- insert into customer values("C1","GANGADHAM","PUNE");
-- insert into customer values("C2","BORIWALI","DELHI");
-- insert into customer values("C3","MG ROAD","MUMBAI");
-- insert into customer values("C4","5TH AVENUE","NEW YORK");
-- insert into customer values("C5","UPSTATE","NEW YORK");
-- insert into customer values("C6","CAMP","PUNE");
-- 
-- insert into loan values(1,"CAMP",1200);
-- insert into loan values(2,"DOWNTOWN",1300);
-- insert into loan values(3,"CAMP",1400);
-- insert into loan values(5,"SWARGATE",1600);
-- 
-- insert into account values(123,"CAMP",9000);
-- insert into account values(345,"DOWNTOWN",8300);
-- insert into account values(567,"SWARGATE",800);
-- insert into account values(789,"DECCAN",90030);
-- insert into account values(901,"CAMP",90110);
-- insert into account values(129,"DECCAN",10);
-- 
-- insert into depositor values("C1", 123);
-- insert into depositor values("C2", 567);
-- insert into depositor values("C3", 345);
-- insert into depositor values("C4", 901);
-- insert into depositor values("C5", 789);
-- insert into depositor values("C6", 129);
-- 
-- insert into borrower values(1,"C1");
-- insert into borrower values(2,"C5");
-- insert into borrower values(3,"C2");
-- insert into borrower values(5,"C3");
-- 
-- SELECT * FROM LOAN;
-- SELECT * FROM CUSTOMER;
-- SELECT * FROM BRANCH;
-- SELECT * FROM ACCOUNT;
-- SELECT * FROM DEPOSITOR;
-- 
-- select distinct branchName from loan;
-- select max(amount) from loan;
-- select loanNo from loan where amount >1000 AND branchName="camp";
-- select min(amount) from loan where amount >1300;
-- select loanNo from loan where amount < 1511 and amount > 1399;
-- select loanNo from loan where amount between 1000 and 1300;
-- select loanNo from loan order by amount asc;
-- select loanNo from loan order by amount desc;
-- select avg(amount) from loan;
-- select loanNo from loan where branchName="CAMP";
-- select avg(amount) from loan where branchName="CAMP";
-- 
-- select customerName from borrower union select customerName from depositor;
-- select name from branch union select branchName from loan;
-- delete from account where balance < (select avg(balance));
-- update account set balance=balance*0.5;
-- update account set balance= balance + 2000 where balance < (select avg(balance));

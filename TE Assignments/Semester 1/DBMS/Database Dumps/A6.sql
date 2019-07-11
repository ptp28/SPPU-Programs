CREATE DATABASE  IF NOT EXISTS `db6` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `db6`;
-- MySQL dump 10.13  Distrib 5.7.17, for macos10.12 (x86_64)
--
-- Host: 127.0.0.1    Database: db6
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
-- Table structure for table `Library`
--

DROP TABLE IF EXISTS `Library`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Library` (
  `ID` int(11) NOT NULL,
  `Name` varchar(20) DEFAULT NULL,
  `Stock` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Library`
--

LOCK TABLES `Library` WRITE;
/*!40000 ALTER TABLE `Library` DISABLE KEYS */;
INSERT INTO `Library` VALUES (102,'CNL',50),(103,'SDL',500),(104,'TOC',150),(105,'SEPM',80);
/*!40000 ALTER TABLE `Library` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Library_aud`
--

DROP TABLE IF EXISTS `Library_aud`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Library_aud` (
  `ID` int(11) DEFAULT NULL,
  `Stock` int(11) DEFAULT NULL,
  `action` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Library_aud`
--

LOCK TABLES `Library_aud` WRITE;
/*!40000 ALTER TABLE `Library_aud` DISABLE KEYS */;
INSERT INTO `Library_aud` VALUES (105,15,'update'),(106,150,'update'),(106,150,'Update'),(106,1,'delete'),(101,100,'delete'),(101,100,'DELETE');
/*!40000 ALTER TABLE `Library_aud` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-10-28 20:25:31

-- 
-- create database db6;
-- use db6;
-- 
-- create table Library(ID int,Name varchar(20),Stock int,primary key(ID));
-- create table Library_aud(ID int , Stock int,action varchar(10));
-- 
-- insert into Library values(101,'DBMS',100);
-- insert into Library values(102,'CNL',50);
--  insert into Library values(103,'SDL',500);
-- insert into Library values(104,'TOC',150);
-- insert into Library values(105,'SEPM',15);
-- insert into Library values(106,'ISEE',150);
-- -- 
-- delimiter $
-- create trigger trig1
-- before update on Library
-- for each row
-- begin
-- insert into Library_aud
-- set action = 'update' ,
-- ID = old.ID , Stock = old.Stock;
-- end$
-- 
-- update Library set Stock = 80 where ID = 105;
-- 
-- delimiter $
-- create trigger trig2
-- after update on Library
-- for each row
-- begin
-- insert into Library_aud
-- set action = 'Update' , 
-- ID = old.ID , Stock = old.Stock;
-- end$
-- 
-- update Library set Stock = 1 where ID = 106; 
-- 
-- delimiter $
-- create trigger trig3
-- before delete on Library
--  for each row
--  begin
--  insert into Library_aud
--  set action = 'delete' ,
-- ID = old.ID , Stock = old.Stock;
-- end$
-- 
-- delete from Library where ID=106;
-- 
-- delimiter $
-- create trigger trig4
-- after delete on Library
--  for each row
-- begin
-- insert into Library_aud
-- set action = 'DELETE' ,
-- ID = old.ID , Stock = old.Stock;
-- end$
-- 
-- delete from Library where ID=101;


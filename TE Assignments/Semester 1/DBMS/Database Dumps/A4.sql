CREATE DATABASE  IF NOT EXISTS `db4` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `db4`;
-- MySQL dump 10.13  Distrib 5.7.17, for macos10.12 (x86_64)
--
-- Host: 127.0.0.1    Database: db4
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
-- Table structure for table `company`
--

DROP TABLE IF EXISTS `company`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `company` (
  `name` varchar(30) NOT NULL,
  `city` text,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `company`
--

LOCK TABLES `company` WRITE;
/*!40000 ALTER TABLE `company` DISABLE KEYS */;
INSERT INTO `company` VALUES ('C1','MUMABI'),('C2','PUNE'),('C3','DELHI'),('C4','LEH'),('C5','SURAT'),('C6','CHENNAI');
/*!40000 ALTER TABLE `company` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employees`
--

DROP TABLE IF EXISTS `employees`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `employees` (
  `name` varchar(30) NOT NULL,
  `address` text NOT NULL,
  `city` text NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employees`
--

LOCK TABLES `employees` WRITE;
/*!40000 ALTER TABLE `employees` DISABLE KEYS */;
INSERT INTO `employees` VALUES ('E1','CAMP','PUNE'),('E2','BORIVALI','MUMABAI'),('E3','MG ROAD','DELHI'),('E4','MAIN STREET','LEH'),('E5','SVBP ROAD','SURAT'),('E6','PORT ROAD','CHENNAI');
/*!40000 ALTER TABLE `employees` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `manages`
--

DROP TABLE IF EXISTS `manages`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `manages` (
  `employeeName` varchar(30) DEFAULT NULL,
  `managerName` varchar(30) NOT NULL,
  PRIMARY KEY (`managerName`),
  KEY `employeeName` (`employeeName`),
  CONSTRAINT `manages_ibfk_1` FOREIGN KEY (`employeeName`) REFERENCES `employees` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `manages`
--

LOCK TABLES `manages` WRITE;
/*!40000 ALTER TABLE `manages` DISABLE KEYS */;
INSERT INTO `manages` VALUES ('E1','M1'),('E2','M2'),('E3','M3'),('E4','M4'),('E5','M5'),('E6','M6');
/*!40000 ALTER TABLE `manages` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `works`
--

DROP TABLE IF EXISTS `works`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `works` (
  `employeeName` varchar(30) NOT NULL,
  `companyName` varchar(30) DEFAULT NULL,
  `salary` int(11) DEFAULT NULL,
  KEY `employeeName` (`employeeName`),
  KEY `companyName` (`companyName`),
  CONSTRAINT `works_ibfk_1` FOREIGN KEY (`employeeName`) REFERENCES `employees` (`name`),
  CONSTRAINT `works_ibfk_2` FOREIGN KEY (`companyName`) REFERENCES `company` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `works`
--

LOCK TABLES `works` WRITE;
/*!40000 ALTER TABLE `works` DISABLE KEYS */;
INSERT INTO `works` VALUES ('E1','C2',50000),('E2','C1',1000),('E3','C3',45000),('E4','C4',55000),('E5','C5',60000),('E6','C6',75500);
/*!40000 ALTER TABLE `works` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-10-28 15:10:47

-- create database db4;
-- use db4;
-- 
-- create table employees(name varchar(30) not null primary key, address text not null , city text not null);
-- create table company(name varchar(30) , city text , primary key(name));
-- create table works(employeeName varchar(30)  not null , companyName varchar(30) , salary int , foreign key(employeeName) references employees(name) , foreign key(companyName) references company(name));
-- create table manages(employeeName varchar(30), managerName varchar(30) not null primary key, foreign key(employeeName) references employees(name));
-- 
-- insert into employees values("E1","CAMP","PUNE");
-- insert into employees values("E2","BORIVALI","MUMABAI");
-- insert into employees values("E3","MG ROAD","DELHI");
-- insert into employees values("E4","MAIN STREET","LEH");
-- insert into employees values("E5","SVBP ROAD","SURAT");
-- insert into employees values("E6","PORT ROAD","CHENNAI");
-- 
-- insert into company values("C1","MUMABI");
-- insert into company values("C2","PUNE");
-- insert into company values("C3","DELHI");
-- insert into company values("C4","LEH");
-- insert into company values("C5","SURAT");
-- insert into company values("C6","CHENNAI");
-- 
-- insert into works values("E1","C2",50000);
-- insert into works values("E2","C1",1000);
-- insert into works values("E3","C3",45000);
-- insert into works values("E4","C4",55000);
-- insert into works values("E5","C5",60000);
-- insert into works values("E6","C6",75500);
-- 
-- insert into manages values("E1","M1");
-- insert into manages values("E2","M2");
-- insert into manages values("E3","M3");
-- insert into manages values("E4","M4");
-- insert into manages values("E5","M5");
-- insert into manages values("E6","M6");
-- 
-- select employeeName from works where companyName="C2";
-- select employeeName from works where salary < (select avg(salary) from works);
-- select employeeName from works where salary > (select avg(salary) from works) AND companyName = "C2";
-- select companyName from works where salary < (select avg(salary) from works);
-- select employees.name,employeeName,address,city from employees,works where companyName="C5" and employees.name = works.employeeName;
-- select managerName,companyName from manages,works where companyName="C5" and manages.employeeName = works.employeeName;
-- select * from company left join works on company.name = works.companyName;
-- select * from company left outer join works on company.name = works.companyName;

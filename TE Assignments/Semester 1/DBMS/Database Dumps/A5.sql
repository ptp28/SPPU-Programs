CREATE DATABASE  IF NOT EXISTS `db5` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `db5`;
-- MySQL dump 10.13  Distrib 5.7.17, for macos10.12 (x86_64)
--
-- Host: 127.0.0.1    Database: db5
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
-- Table structure for table `rollcallNEW`
--

DROP TABLE IF EXISTS `rollcallNEW`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rollcallNEW` (
  `rollno` int(11) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `address` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`rollno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rollcallNEW`
--

LOCK TABLES `rollcallNEW` WRITE;
/*!40000 ALTER TABLE `rollcallNEW` DISABLE KEYS */;
INSERT INTO `rollcallNEW` VALUES (1,'S1','PUNE'),(2,'S2','MUMBAI'),(5,'S5','PUNE');
/*!40000 ALTER TABLE `rollcallNEW` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rollcallOLD`
--

DROP TABLE IF EXISTS `rollcallOLD`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rollcallOLD` (
  `rollno` int(11) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `address` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`rollno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rollcallOLD`
--

LOCK TABLES `rollcallOLD` WRITE;
/*!40000 ALTER TABLE `rollcallOLD` DISABLE KEYS */;
INSERT INTO `rollcallOLD` VALUES (1,'S1','PUNE'),(2,'S2','MUMBAI'),(3,'S3','DELHI'),(4,'S4','PUNE'),(5,'S5','PUNE');
/*!40000 ALTER TABLE `rollcallOLD` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-10-29 10:52:40


-- create database db5;
-- use db5;
-- create table rollcallOLD(rollno int primary key,name varchar(20),address varchar(30));
-- create table rollcallNEW(rollno int primary key,name varchar(20),address varchar(30));
-- 
-- insert into rollcallOLD values(1,'S1','PUNE');
-- insert into rollcallOLD values(2,'S2','MUMBAI');
-- insert into rollcallOLD values(3,'S3','DELHI');
-- insert into rollcallOLD values(4,'S4','PUNE');
-- insert into rollcallOLD values(5,'S5','PUNE');
-- 
-- delimiter $
-- create procedure newcursor2(IN rollno1 int)
--  begin
--  declare rollno2 int;
--  declare exit_loop boolean;
-- declare c1 cursor for select rollno from rollcallOLD where rollno=rollno1 ;
-- declare continue handler for not found set exit_loop=true;
-- open c1;
--  emp_loop:loop
--  fetch c1 into rollno2;
--  if not exists (select * from rollcallNEW where rollno=rollno2) then
--  insert into rollcallNEW select * from rollcallOLD where rollno=rollno2;
--  end if;
--  if exit_loop then
--  close c1;
-- leave emp_loop;
--  end if;
--  end loop emp_loop;
--  end$
--  
--  delimiter ;
-- call newcursor2(1);
-- call newcursor2(5);
-- call newcursor2(2);
-- 
CREATE DATABASE  IF NOT EXISTS `db2` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `db2`;
-- MySQL dump 10.13  Distrib 5.7.17, for macos10.12 (x86_64)
--
-- Host: 127.0.0.1    Database: db2
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
-- Table structure for table `StudentDetails`
--

DROP TABLE IF EXISTS `StudentDetails`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `StudentDetails` (
  `rollNo` int(11) DEFAULT NULL,
  `name` text,
  `marks` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `StudentDetails`
--

LOCK TABLES `StudentDetails` WRITE;
/*!40000 ALTER TABLE `StudentDetails` DISABLE KEYS */;
INSERT INTO `StudentDetails` VALUES (2,'s2',NULL),(3,'s3',NULL),(4,'s4',NULL);
/*!40000 ALTER TABLE `StudentDetails` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `pass`
--

DROP TABLE IF EXISTS `pass`;
/*!50001 DROP VIEW IF EXISTS `pass`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE VIEW `pass` AS SELECT 
 1 AS `rollNo`,
 1 AS `name`,
 1 AS `marks`*/;
SET character_set_client = @saved_cs_client;

--
-- Final view structure for view `pass`
--

/*!50001 DROP VIEW IF EXISTS `pass`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `pass` AS select `studentdetails`.`rollNo` AS `rollNo`,`studentdetails`.`name` AS `name`,`studentdetails`.`marks` AS `marks` from `studentdetails` where (`studentdetails`.`rollNo` > 2) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-10-27 14:34:56
-- 
-- select * from StudentDetails;
-- describe StudentDetails; 
-- alter table StudentDetails drop marks;
-- delete from StudentDetails where rollNo=1;
-- SET SQL_SAFE_UPDATES = 0;
-- 
-- alter table StudentDetails add marks int;
-- alter table StudentDetails modify column marks float; 
-- 
-- create index index1 on StudentDetails(rollNo);
-- alter table StudentDetails 
-- drop index index1;
-- 
-- create view PASS as 
-- select * from StudentDetails where rollNo > 2;
-- 
-- Select * from PASS;
-- 
-- drop view PASS;

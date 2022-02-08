-- MySQL dump 10.13  Distrib 8.0.27, for Linux (x86_64)
--
-- Host: 127.0.0.1    Database: LY-core
-- ------------------------------------------------------
-- Server version	8.0.27

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `BaseInfo`
--

DROP TABLE IF EXISTS `BaseInfo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `BaseInfo` (
  `domainname` varchar(45) DEFAULT NULL,
  `machine` varchar(45) DEFAULT NULL,
  `sysrelease` varchar(45) DEFAULT NULL,
  `sysname` varchar(45) DEFAULT NULL,
  `version` varchar(100) DEFAULT NULL,
  `bufferram` bigint DEFAULT NULL,
  `freehigh` varchar(45) DEFAULT NULL,
  `freeswap` bigint DEFAULT NULL,
  `mem_unit` int DEFAULT NULL,
  `pad` int DEFAULT NULL,
  `sharedram` bigint DEFAULT NULL,
  `totalhigh` int DEFAULT NULL,
  `uptime` int DEFAULT NULL,
  `procs` int DEFAULT NULL,
  `ip` varchar(45) NOT NULL,
  PRIMARY KEY (`ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `BaseInfo`
--

LOCK TABLES `BaseInfo` WRITE;
/*!40000 ALTER TABLE `BaseInfo` DISABLE KEYS */;
INSERT INTO `BaseInfo` VALUES ('(none)','x86_64','5.13.0-27-generic','Linux','#29~20.04.1-Ubuntu SMP Fri Jan 14 00:32:30 UTC 2022',109666304,'0',1144516608,1,0,35647488,0,2917,1112,'192.168.1.30'),('(none)','x86_64','5.13.0-27-generic','Linux','#29~20.04.1-Ubuntu SMP Fri Jan 14 00:32:30 UTC 2022',177410048,'0',34340864,1,0,11853824,0,5589,1155,'192.168.252.1');
/*!40000 ALTER TABLE `BaseInfo` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-02-08 15:09:59

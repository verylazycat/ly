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
-- Table structure for table `Firewall`
--

DROP TABLE IF EXISTS `Firewall`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Firewall` (
  `ip` varchar(45) NOT NULL,
  `rules` text,
  PRIMARY KEY (`ip`),
  CONSTRAINT `Firewall_ibfk_1` FOREIGN KEY (`ip`) REFERENCES `BaseInfo` (`ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Firewall`
--

LOCK TABLES `Firewall` WRITE;
/*!40000 ALTER TABLE `Firewall` DISABLE KEYS */;
INSERT INTO `Firewall` VALUES ('192.168.1.30','Chain INPUT (policy ACCEPT)\ntarget     prot opt source               destination         \nACCEPT     tcp  --  anywhere             anywhere             tcp dpt:domain /* managed by xdroid-bridge */\nACCEPT     udp  --  anywhere             anywhere             udp dpt:domain /* managed by xdroid-bridge */\nACCEPT     tcp  --  anywhere             anywhere             tcp dpt:67 /* managed by xdroid-bridge */\nACCEPT     udp  --  anywhere             anywhere             udp dpt:bootps /* managed by xdroid-bridge */\n\nChain FORWARD (policy DROP)\ntarget     prot opt source               destination         \nACCEPT     all  --  anywhere             anywhere             /* managed by xdroid-bridge */\nACCEPT     all  --  anywhere             anywhere             /* managed by xdroid-bridge */\nDOCKER-USER  all  --  anywhere             anywhere            \nDOCKER-ISOLATION-STAGE-1  all  --  anywhere             anywhere            \nACCEPT     all  --  anywhere             anywhere             ctstate RELATED,ESTABLISHED\nDOCKER     all  --  anywhere             anywhere            \nACCEPT     all  --  anywhere             anywhere            \nACCEPT     all  --  anywhere             anywhere            \n\nChain OUTPUT (policy ACCEPT)\ntarget     prot opt source               destination         \n\nChain DOCKER (1 references)\ntarget     prot opt source               destination         \n\nChain DOCKER-ISOLATION-STAGE-1 (1 references)\ntarget     prot opt source               destination         \nDOCKER-ISOLATION-STAGE-2  all  --  anywhere             anywhere            \nRETURN     all  --  anywhere             anywhere            \n\nChain DOCKER-ISOLATION-STAGE-2 (1 references)\ntarget     prot opt source               destination         \nDROP       all  --  anywhere             anywhere            \nRETURN     all  --  anywhere             anywhere            \n\nChain DOCKER-USER (1 references)\ntarget     prot opt source               destination         \nRETURN     all  --  anywhere             anywhere            \n'),('192.168.252.1','Chain INPUT (policy ACCEPT)\ntarget     prot opt source               destination         \nACCEPT     tcp  --  anywhere             anywhere             tcp dpt:domain /* managed by xdroid-bridge */\nACCEPT     udp  --  anywhere             anywhere             udp dpt:domain /* managed by xdroid-bridge */\nACCEPT     tcp  --  anywhere             anywhere             tcp dpt:67 /* managed by xdroid-bridge */\nACCEPT     udp  --  anywhere             anywhere             udp dpt:bootps /* managed by xdroid-bridge */\n\nChain FORWARD (policy DROP)\ntarget     prot opt source               destination         \nACCEPT     all  --  anywhere             anywhere             /* managed by xdroid-bridge */\nACCEPT     all  --  anywhere             anywhere             /* managed by xdroid-bridge */\nDOCKER-USER  all  --  anywhere             anywhere            \nDOCKER-ISOLATION-STAGE-1  all  --  anywhere             anywhere            \nACCEPT     all  --  anywhere             anywhere             ctstate RELATED,ESTABLISHED\nDOCKER     all  --  anywhere             anywhere            \nACCEPT     all  --  anywhere             anywhere            \nACCEPT     all  --  anywhere             anywhere            \n\nChain OUTPUT (policy ACCEPT)\ntarget     prot opt source               destination         \n\nChain DOCKER (1 references)\ntarget     prot opt source               destination         \n\nChain DOCKER-ISOLATION-STAGE-1 (1 references)\ntarget     prot opt source               destination         \nDOCKER-ISOLATION-STAGE-2  all  --  anywhere             anywhere            \nRETURN     all  --  anywhere             anywhere            \n\nChain DOCKER-ISOLATION-STAGE-2 (1 references)\ntarget     prot opt source               destination         \nDROP       all  --  anywhere             anywhere            \nRETURN     all  --  anywhere             anywhere            \n\nChain DOCKER-USER (1 references)\ntarget     prot opt source               destination         \nRETURN     all  --  anywhere             anywhere            \n');
/*!40000 ALTER TABLE `Firewall` ENABLE KEYS */;
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

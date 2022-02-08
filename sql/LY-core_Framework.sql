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
-- Table structure for table `Framework`
--

DROP TABLE IF EXISTS `Framework`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Framework` (
  `ip` varchar(45) NOT NULL,
  `apparmor_status` text,
  PRIMARY KEY (`ip`),
  CONSTRAINT `Framework_ibfk_1` FOREIGN KEY (`ip`) REFERENCES `BaseInfo` (`ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Framework`
--

LOCK TABLES `Framework` WRITE;
/*!40000 ALTER TABLE `Framework` DISABLE KEYS */;
INSERT INTO `Framework` VALUES ('192.168.1.30','apparmor module is loaded.\n30 profiles are loaded.\n28 profiles are in enforce mode.\n   /usr/bin/evince\n   /usr/bin/evince-previewer\n   /usr/bin/evince-previewer//sanitized_helper\n   /usr/bin/evince-thumbnailer\n   /usr/bin/evince//sanitized_helper\n   /usr/bin/freshclam\n   /usr/bin/man\n   /usr/lib/NetworkManager/nm-dhcp-client.action\n   /usr/lib/NetworkManager/nm-dhcp-helper\n   /usr/lib/connman/scripts/dhclient-script\n   /usr/lib/cups/backend/cups-pdf\n   /usr/sbin/clamd\n   /usr/sbin/cups-browsed\n   /usr/sbin/cupsd\n   /usr/sbin/cupsd//third_party\n   /usr/sbin/mysqld\n   /usr/sbin/tcpdump\n   /{,usr/}sbin/dhclient\n   docker-default\n   ippusbxd\n   libreoffice-senddoc\n   libreoffice-soffice//gpg\n   libreoffice-xpdfimport\n   lsb_release\n   man_filter\n   man_groff\n   nvidia_modprobe\n   nvidia_modprobe//kmod\n2 profiles are in complain mode.\n   libreoffice-oopslash\n   libreoffice-soffice\n5 processes have profiles defined.\n5 processes are in enforce mode.\n   /usr/bin/freshclam (1719) \n   /usr/sbin/clamd (845) \n   /usr/sbin/cups-browsed (907) \n   /usr/sbin/cupsd (794) \n   /usr/sbin/mysqld (1015) \n0 processes are in complain mode.\n0 processes are unconfined but have a profile defined.\n'),('192.168.252.1','apparmor module is loaded.\n30 profiles are loaded.\n28 profiles are in enforce mode.\n   /usr/bin/evince\n   /usr/bin/evince-previewer\n   /usr/bin/evince-previewer//sanitized_helper\n   /usr/bin/evince-thumbnailer\n   /usr/bin/evince//sanitized_helper\n   /usr/bin/freshclam\n   /usr/bin/man\n   /usr/lib/NetworkManager/nm-dhcp-client.action\n   /usr/lib/NetworkManager/nm-dhcp-helper\n   /usr/lib/connman/scripts/dhclient-script\n   /usr/lib/cups/backend/cups-pdf\n   /usr/sbin/clamd\n   /usr/sbin/cups-browsed\n   /usr/sbin/cupsd\n   /usr/sbin/cupsd//third_party\n   /usr/sbin/mysqld\n   /usr/sbin/tcpdump\n   /{,usr/}sbin/dhclient\n   docker-default\n   ippusbxd\n   libreoffice-senddoc\n   libreoffice-soffice//gpg\n   libreoffice-xpdfimport\n   lsb_release\n   man_filter\n   man_groff\n   nvidia_modprobe\n   nvidia_modprobe//kmod\n2 profiles are in complain mode.\n   libreoffice-oopslash\n   libreoffice-soffice\n5 processes have profiles defined.\n5 processes are in enforce mode.\n   /usr/bin/freshclam (1719) \n   /usr/sbin/clamd (845) \n   /usr/sbin/cups-browsed (907) \n   /usr/sbin/cupsd (794) \n   /usr/sbin/mysqld (1015) \n0 processes are in complain mode.\n0 processes are unconfined but have a profile defined.\n');
/*!40000 ALTER TABLE `Framework` ENABLE KEYS */;
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

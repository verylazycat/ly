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
-- Table structure for table `FileIntegrity`
--

DROP TABLE IF EXISTS `FileIntegrity`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `FileIntegrity` (
  `ip` varchar(45) NOT NULL,
  `home_block_info` text,
  `tmp_block_info` text,
  `swap_block_configured` int DEFAULT '1',
  `tmp_info` text,
  `aide_conf` text,
  `tmp_bit` int DEFAULT '1',
  PRIMARY KEY (`ip`),
  CONSTRAINT `FileIntegrity_ibfk_1` FOREIGN KEY (`ip`) REFERENCES `BaseInfo` (`ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `FileIntegrity`
--

LOCK TABLES `FileIntegrity` WRITE;
/*!40000 ALTER TABLE `FileIntegrity` DISABLE KEYS */;
INSERT INTO `FileIntegrity` VALUES ('192.168.1.30','文件系统        容量  已用  可用 已用% 挂载点\n/dev/sda2       234G  172G   51G   78% /\n','文件系统        容量  已用  可用 已用% 挂载点\n/dev/sda2       234G  172G   51G   78% /\n',1,'/tmp/segv_output.mvKOVQ\n/tmp/sunlogin_rundaemon.log\n/tmp/tmpjn621jeo.svg\n/tmp/mysql-workbench-4177/4b373146-7ff6-11ec-93fc-a91676d39bcf.db\n/tmp/mysql-workbench-4177/86176bce-7ffb-11ec-93fc-a91676d39bcf.db\n/tmp/mysql-workbench-4177/4b373142-7ff6-11ec-93fc-a91676d39bcf.db\n/tmp/mysql-workbench-4177/4b373143-7ff6-11ec-93fc-a91676d39bcf.db\n/tmp/mysql-workbench-4177/4b373144-7ff6-11ec-93fc-a91676d39bcf.db\n/tmp/winstone8395088055061876333.jar\n/tmp/hsperfdata_root/2030\n/tmp/config-err-FHu1t7\n/tmp/sogoupinyin-qimpanel-watchdog-1000:0.pid\n',NULL,1),('192.168.252.1','文件系统        容量  已用  可用 已用% 挂载点\n/dev/sda2       234G  172G   51G   78% /\n','文件系统        容量  已用  可用 已用% 挂载点\n/dev/sda2       234G  172G   51G   78% /\n',1,'/tmp/hsperfdata_admin233/18539\n/tmp/loose/6142509188972423790/.browse.VC.db\n/tmp/sunlogin_rundaemon.log\n/tmp/tmpjn621jeo.svg\n/tmp/mysql-workbench-4177/68707920-7ffc-11ec-93fc-a91676d39bcf.db\n/tmp/setup.sh.8Mud7fGPAB\n/tmp/winstone8395088055061876333.jar\n/tmp/hsperfdata_root/2030\n/tmp/config-err-FHu1t7\n/tmp/sogoupinyin-qimpanel-watchdog-1000:0.pid\n/tmp/librocksdbjni7152303809748140649.so\n',NULL,1);
/*!40000 ALTER TABLE `FileIntegrity` ENABLE KEYS */;
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

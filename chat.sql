/*
 Navicat Premium Data Transfer

 Source Server         : Ubuntu20.04
 Source Server Type    : MySQL
 Source Server Version : 80037 (8.0.37-0ubuntu0.20.04.3)
 Source Host           : 192.168.80.129:3306
 Source Schema         : chat

 Target Server Type    : MySQL
 Target Server Version : 80037 (8.0.37-0ubuntu0.20.04.3)
 File Encoding         : 65001

 Date: 29/07/2024 23:49:44
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for allgroup
-- ----------------------------
DROP TABLE IF EXISTS `allgroup`;
CREATE TABLE `allgroup`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `groupname` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `groupdesc` varchar(200) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `groupname`(`groupname` ASC) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 2 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of allgroup
-- ----------------------------
INSERT INTO `allgroup` VALUES (1, 'C++ project Cluster_ChatServer', 'sfbu advanced linux course project');

-- ----------------------------
-- Table structure for friend
-- ----------------------------
DROP TABLE IF EXISTS `friend`;
CREATE TABLE `friend`  (
  `userid` int NOT NULL AUTO_INCREMENT,
  `friendid` int NOT NULL,
  PRIMARY KEY (`userid`) USING BTREE,
  INDEX `userid`(`userid` ASC, `friendid` ASC) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 3 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of friend
-- ----------------------------
INSERT INTO `friend` VALUES (1, 2);
INSERT INTO `friend` VALUES (2, 3);

-- ----------------------------
-- Table structure for groupuser
-- ----------------------------
DROP TABLE IF EXISTS `groupuser`;
CREATE TABLE `groupuser`  (
  `groupid` int NOT NULL,
  `userid` int NOT NULL,
  `grouprole` enum('creator','normal') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  INDEX `groupid`(`groupid` ASC, `userid` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of groupuser
-- ----------------------------
INSERT INTO `groupuser` VALUES (1, 1, 'creator');
INSERT INTO `groupuser` VALUES (2, 1, 'normal');

-- ----------------------------
-- Table structure for offlinemessage
-- ----------------------------
DROP TABLE IF EXISTS `offlinemessage`;
CREATE TABLE `offlinemessage`  (
  `userid` int NOT NULL,
  `message` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of offlinemessage
-- ----------------------------
INSERT INTO `offlinemessage` VALUES (1, '{\"groupid\":1, \r\n	\"id\":1, \r\n	\"msg\":\"hello SFBU\", \r\n	\"msgid\":1, \r\n	\"name\":\"Beza\", \r\n	\"time\":\"2024-07-29 22:43:21\"}');
INSERT INTO `offlinemessage` VALUES (1, '{\"groupid\":1, \r\n	\"id\":2, \r\n	\"msg\":\"hello California\", \r\n	\"msgid\":1, \r\n	\"name\":\"Lee\", \r\n	\"time\":\"2024-07-29 22:44:22\"}');

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user`  (
  `id` int NOT NULL,
  `name` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `password` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `state` enum('online','offline') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `name`(`name` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES (1, 'beza', '123456', 'online');
INSERT INTO `user` VALUES (2, 'Lee', '123456', 'offline');

SET FOREIGN_KEY_CHECKS = 1;

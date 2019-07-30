-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jul 29, 2019 at 08:49 PM
-- Server version: 10.1.38-MariaDB
-- PHP Version: 7.3.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `recording_studio`
--

-- --------------------------------------------------------

--
-- Table structure for table `albums`
--

CREATE TABLE `albums` (
  `id` int(11) NOT NULL,
  `name` varchar(15) NOT NULL,
  `start_date` date NOT NULL,
  `end_date` date NOT NULL,
  `songs_number` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `albums`
--

INSERT INTO `albums` (`id`, `name`, `start_date`, `end_date`, `songs_number`) VALUES
(1, 'album1', '2002-02-02', '2002-12-10', 1),
(2, 'album2', '2016-04-04', '2016-09-11', 2);

-- --------------------------------------------------------

--
-- Table structure for table `albums_producers`
--

CREATE TABLE `albums_producers` (
  `album_id` int(11) NOT NULL,
  `producer_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `albums_producers`
--

INSERT INTO `albums_producers` (`album_id`, `producer_id`) VALUES
(1, 1),
(1, 4),
(2, 3),
(2, 4);

-- --------------------------------------------------------

--
-- Table structure for table `band`
--

CREATE TABLE `band` (
  `musician_id` int(11) NOT NULL,
  `instrument_id` int(11) NOT NULL,
  `song_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `band`
--

INSERT INTO `band` (`musician_id`, `instrument_id`, `song_id`) VALUES
(1, 0, 3),
(1, 5, 2),
(2, 1, 2),
(2, 3, 1),
(2, 4, 3),
(5, 3, 2),
(8, 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `musical_instruments`
--

CREATE TABLE `musical_instruments` (
  `id` int(11) NOT NULL,
  `type` varchar(15) NOT NULL,
  `manufacturer` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `musical_instruments`
--

INSERT INTO `musical_instruments` (`id`, `type`, `manufacturer`) VALUES
(1, 'guitar', 'Martin'),
(2, 'guitar', 'Yamaha'),
(3, 'piano ', 'Bösendorfer'),
(4, 'piano ', 'Bechstein'),
(5, 'Drum', 'Pearl '),
(6, 'Drum', 'Gretsch ');

-- --------------------------------------------------------

--
-- Table structure for table `musicians`
--

CREATE TABLE `musicians` (
  `id` int(11) NOT NULL,
  `name` varchar(15) NOT NULL,
  `address` varchar(15) NOT NULL,
  `phone_number` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `musicians`
--

INSERT INTO `musicians` (`id`, `name`, `address`, `phone_number`) VALUES
(1, 'koko', 'koko', '0541234567'),
(2, 'lolo', 'lolo', '0547654321'),
(5, 'nono', 'nono', '0541234567'),
(6, 'soso', 'soso', '0541234567'),
(7, 'fofo', 'fofo', '0541234567'),
(8, 'bobo', 'bobo', '0547654321');

-- --------------------------------------------------------

--
-- Table structure for table `producers`
--

CREATE TABLE `producers` (
  `id` int(11) NOT NULL,
  `name` varchar(15) NOT NULL,
  `address` varchar(15) NOT NULL,
  `about` varchar(15) NOT NULL,
  `phone_number` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `producers`
--

INSERT INTO `producers` (`id`, `name`, `address`, `about`, `phone_number`) VALUES
(1, 'p1', 'p1', 'p1', '0581234569'),
(2, 'p2', 'p2', 'p2', '0589638521'),
(3, 'p3', 'p3', 'p3', '0527418542'),
(4, 'p4', 'p4', 'p4', '0548529637');

-- --------------------------------------------------------

--
-- Table structure for table `songs`
--

CREATE TABLE `songs` (
  `id` int(11) NOT NULL,
  `name` varchar(15) NOT NULL,
  `about_words_author` varchar(15) NOT NULL,
  `about_composer_author` varchar(15) NOT NULL,
  `time_length` int(11) NOT NULL,
  `type` varchar(15) NOT NULL,
  `date` date NOT NULL,
  `album_id` int(11) NOT NULL,
  `technician_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `songs`
--

INSERT INTO `songs` (`id`, `name`, `about_words_author`, `about_composer_author`, `time_length`, `type`, `date`, `album_id`, `technician_id`) VALUES
(1, 's1', 'a1', 'c1', 30, 'jaz', '2002-10-10', 1, 1),
(2, 's2', 'a2', 'c2', 69, 'bob', '2016-05-06', 2, 2),
(3, 's3', 'a3', 'c3', 120, 'house', '2016-07-28', 2, 3);

-- --------------------------------------------------------

--
-- Table structure for table `technicians`
--

CREATE TABLE `technicians` (
  `id` int(11) NOT NULL,
  `name` varchar(15) NOT NULL,
  `address` varchar(15) NOT NULL,
  `phone_number` varchar(15) NOT NULL,
  `seniority` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `technicians`
--

INSERT INTO `technicians` (`id`, `name`, `address`, `phone_number`, `seniority`) VALUES
(1, 't1', 't1', '0529876543', 2),
(2, 't2', 't2', '0522345678', 1),
(3, 't3', 't3', '0539876543', 2),
(4, 't4', 't4', '053456789', 3);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `albums`
--
ALTER TABLE `albums`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `name` (`name`);

--
-- Indexes for table `albums_producers`
--
ALTER TABLE `albums_producers`
  ADD PRIMARY KEY (`album_id`,`producer_id`),
  ADD KEY `producer_id` (`producer_id`);

--
-- Indexes for table `band`
--
ALTER TABLE `band`
  ADD PRIMARY KEY (`musician_id`,`instrument_id`,`song_id`),
  ADD KEY `instrument_id` (`instrument_id`),
  ADD KEY `song_id` (`song_id`);

--
-- Indexes for table `musical_instruments`
--
ALTER TABLE `musical_instruments`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `musicians`
--
ALTER TABLE `musicians`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `name` (`name`);

--
-- Indexes for table `producers`
--
ALTER TABLE `producers`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `name` (`name`);

--
-- Indexes for table `songs`
--
ALTER TABLE `songs`
  ADD PRIMARY KEY (`id`),
  ADD KEY `technician_id` (`technician_id`),
  ADD KEY `album_id` (`album_id`);

--
-- Indexes for table `technicians`
--
ALTER TABLE `technicians`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `albums`
--
ALTER TABLE `albums`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `musical_instruments`
--
ALTER TABLE `musical_instruments`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `musicians`
--
ALTER TABLE `musicians`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `producers`
--
ALTER TABLE `producers`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `technicians`
--
ALTER TABLE `technicians`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `albums_producers`
--
ALTER TABLE `albums_producers`
  ADD CONSTRAINT `albums_producers_ibfk_2` FOREIGN KEY (`producer_id`) REFERENCES `producers` (`id`),
  ADD CONSTRAINT `albums_producers_ibfk_3` FOREIGN KEY (`album_id`) REFERENCES `albums` (`id`);

--
-- Constraints for table `band`
--
ALTER TABLE `band`
  ADD CONSTRAINT `band_ibfk_2` FOREIGN KEY (`musician_id`) REFERENCES `musicians` (`id`),
  ADD CONSTRAINT `band_ibfk_3` FOREIGN KEY (`song_id`) REFERENCES `songs` (`id`);

--
-- Constraints for table `songs`
--
ALTER TABLE `songs`
  ADD CONSTRAINT `songs_ibfk_1` FOREIGN KEY (`technician_id`) REFERENCES `technicians` (`id`),
  ADD CONSTRAINT `songs_ibfk_2` FOREIGN KEY (`album_id`) REFERENCES `albums` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

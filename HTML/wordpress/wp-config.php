<?php

/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the website, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://developer.wordpress.org/advanced-administration/wordpress/wp-config/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('DB_NAME', 'wp');

/** Database username */
define('DB_USER', 'wp');

/** Database password */
define('DB_PASSWORD', 'root');

/** Database hostname */
define('DB_HOST', 'localhost');

/** Database charset to use in creating database tables. */
define('DB_CHARSET', 'utf8mb4');

/** The database collate type. Don't change this if in doubt. */
define('DB_COLLATE', '');

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'I)z:Ss&,YSPk*JrF`Z}K]r2LKJdy#1=lcvse._~)jw;.ct4#WYBhyv$_=.tHxINj');
define('SECURE_AUTH_KEY',  'O1fQC#,tkPPMn(xI/~E8t++-A`{DLg8#2<9oz92.i#yPTDw1+4)I:&WdW:RhYv@@');
define('LOGGED_IN_KEY',    'Yd?Y5O&f*`<kp?>:jmSTY$nOIH,MqnW1M}}aHl))R[9zJ?f~~,@(N3K U/^;XQkC');
define('NONCE_KEY',        '^wwf-hO8Zdm`Z?,[`PtxXJFZdAu*%t11MqyUQAC~C?KD6%XwD|-Kc&~{Ao_9zhR=');
define('AUTH_SALT',        'WhVf|+v0U~+muz@7*ub(TE|Ikj5]](`aTv/l|K/^.Wj$XbK;1U&R*I{T>p3DN+n^');
define('SECURE_AUTH_SALT', 'GmX7P%V3a#9&vFQE# ?O6Yur<Uo4?383qrFA.)zdud)yk.//et{Cs[FA)|WCkmCo');
define('LOGGED_IN_SALT',   'wzw;^v)b.jjfUM*X]z<D%x4vL0EQ,AyigI*p0a_lfS6Ed,#NwyRqJ^pUIy|Z>N,o');
define('NONCE_SALT',       'd;#vHp0[w&yoK/mH<u+A*&:ld` MKHdAhnrW?9`wjqg:O3P#l*(AL6.qtW}..O.+');

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 *
 * At the installation time, database tables are created with the specified prefix.
 * Changing this value after WordPress is installed will make your site think
 * it has not been installed.
 *
 * @link https://developer.wordpress.org/advanced-administration/wordpress/wp-config/#table-prefix
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://developer.wordpress.org/advanced-administration/debug/debug-wordpress/
 */
define('WP_DEBUG', false);

/* Add any custom values between this line and the "stop editing" line. */


define('FS_METHOD', 'direct');
/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if (! defined('ABSPATH')) {
	define('ABSPATH', __DIR__ . '/');
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';

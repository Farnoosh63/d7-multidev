<?php
// Import all config changes.

//Clear all cache
echo "Rebuilding cache.\n";
passthru('drush cc all');
echo "Rebuilding cache complete.\n";

// Update DB
echo "Updating DB . . .\n";
passthru('drush -y updatedb');
echo "Updating DB complete.\n";

// Feature revert
echo "Reverting features\n";
passthru('drush -y fra');
echo "Revert features complete.\n";

//Clear all cache again
echo "Rebuilding cache.\n";
passthru('drush cc all');
echo "Rebuilding cache complete.\n";

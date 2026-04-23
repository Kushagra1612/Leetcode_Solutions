SELECT customer_number
from orders
GROUP BY customer_number 
ORDER BY COUNT(*) DESC
LIMIT 1;
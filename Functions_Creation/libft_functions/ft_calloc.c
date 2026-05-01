
#include "libft.h"

// size_t nmemb  // Number of elements to allocate
// size_t size   // Size in bytes of each element

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, nmemb * size);
	return (p);
}

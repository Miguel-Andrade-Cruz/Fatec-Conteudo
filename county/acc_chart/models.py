from django.db import models


class Account(models.Model):
    code = models.CharField(max_length=1)
    label = models.CharField(max_length=50)

    def __str__(self):
        return self.label


class Segment(models.Model):
    code = models.CharField(max_length=1)
    label = models.CharField(max_length=50)

    def __str__(self):
        return self.label


class Niche(models.Model):
    code = models.CharField(max_length=1)
    label = models.CharField(max_length=50)

    def __str__(self):
        return self.label



class Chart(models.Model):

    acc = models.ForeignKey(Account, on_delete=models.PROTECT)

    segm = models.ForeignKey(Segment, on_delete=models.PROTECT)

    niche = models.ForeignKey(Niche, on_delete=models.PROTECT)

    class Meta:
        constraints = [
            models.UniqueConstraint(
                fields=['acc', 'segm', 'niche'],
                name='chart_code'
            )
        ]

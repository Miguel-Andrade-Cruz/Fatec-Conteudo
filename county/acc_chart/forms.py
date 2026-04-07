from django import forms

from .middleware import pull_accounts


class AccountForm(forms.Form):

    prev_accounts = forms.ChoiceField(choices=pull_accounts(), required=False)
    new_account = forms.CharField(max_length=50, required=False)


class SegmentForm(forms.Form):


    CHOICES = {}
    prev_segments = forms.ChoiceField(choices=CHOICES, required= False)
    new_segment = forms.CharField(max_length=50, required= False)




class NicheForm(forms.Form):

    new_niche = forms.CharField(max_length=50)
